#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Multiset 
{
private:
    struct tree 
    {
        T value;
        int priority;
        int size;
        shared_ptr<tree> left;
        shared_ptr<tree> right;
        weak_ptr<tree> parent;    
        tree(T val,shared_ptr<tree> p=nullptr):value(val),priority(rand()),size(1),left(nullptr),right(nullptr),parent(p){}
    };
    using NodePtr=shared_ptr<tree>;
    NodePtr root;
    void updateSize(NodePtr node){if(node) node->size=1+getSize(node->left)+getSize(node->right);}
    int getSize(NodePtr node)const{return node?node->size:0;}
    NodePtr merge(NodePtr left,NodePtr right) 
    {
        if(!left) return right;
        if(!right) return left;
        if(left->priority>right->priority) 
        {
            left->right=merge(left->right,right);
            if(left->right) left->right->parent=left;
            updateSize(left);
            return left;
        } 
        else 
        {
            right->left=merge(left,right->left);
            if(right->left) right->left->parent=right;
            updateSize(right);
            return right;
        }
    }
    void split(NodePtr node,const T& key,NodePtr& left,NodePtr& right) 
    {
        if(!node) 
        {
            left=right=nullptr;
            return;
        }
        if(node->value<=key) 
        {
            left=node;
            split(node->right, key, left->right, right);
            if (left->right) 
                left->right->parent = left;
        } 
        else 
        {
            right=node;
            split(node->left,key,left,right->left);
            if(right->left)
                right->left->parent=right;
        }
        updateSize(node);
    }
    void splitStrict(NodePtr node,const T& key,NodePtr& left,NodePtr& right) 
    {
        if(!node) 
        {
            left=right=nullptr;
            return;
        }
        if(node->value<key) 
        {
            left=node;
            splitStrict(node->right,key,left->right,right);
            if(left->right) 
                left->right->parent=left;
        } 
        else 
        {
            right=node;
            splitStrict(node->left,key,left,right->left);
            if(right->left) 
                right->left->parent=right;
        }
        updateSize(node);
    }
    NodePtr findMin(NodePtr node) const 
    {
        while(node&&node->left) 
            node=node->left;
        return node;
    }
    NodePtr findMax(NodePtr node) const 
    {
        while(node&&node->right)
            node=node->right;
        return node;
    }
public:
    Multiset():root(nullptr){}
    void insert(const T& value) 
    {
        NodePtr left, right;
        split(root,value,left,right);    
        NodePtr newNode=make_shared<tree>(value);
        root=merge(merge(left, newNode),right);
    }
    void erase(const T& value) 
    {
        NodePtr left,mid,right;
        splitStrict(root,value,left,mid);
        split(mid,value,mid,right);
        if(mid) 
            mid=merge(mid->left,mid->right);
        root=merge(merge(left,mid),right);
    }
    int count(const T& value) 
    {  
        NodePtr left,mid,right;
        splitStrict(root,value,left,mid);
        split(mid,value,mid,right);
        int cnt=getSize(mid);
        root=merge(merge(left,mid),right);
        return cnt; 
    }
    void clear(){root.reset();}
    int size()const{return getSize(root);}
    bool empty()const{return !root;}
    class Iterator 
    {
    private:
        NodePtr now;
        NodePtr root;
        NodePtr findNext(NodePtr node) const 
        {
            if(!node) return nullptr;
            if(node->right) 
            {
                NodePtr result=node->right;
                while(result->left)
                    result=result->left;
                return result;
            }
            NodePtr parent=node->parent.lock();
            while(parent&&node==parent->right) 
            {
                node=parent;
                parent=parent->parent.lock();
            }
            return parent;
        }
        NodePtr findPrev(NodePtr node) const 
        {
            if(!node) return nullptr;
            if(node->left) 
            {
                NodePtr result=node->left;
                while(result->right) 
                    result=result->right;
                return result;
            }
            NodePtr parent=node->parent.lock();
            while(parent&&node==parent->left) 
            {
                node=parent;
                parent=parent->parent.lock();
            }
            return parent;
        }
        NodePtr findMaxInSubtree(NodePtr node) const 
        {
            while(node&&node->right)
                node=node->right;
            return node;
        }
    public:
        Iterator(NodePtr node=nullptr, NodePtr rootNode=nullptr):now(node),root(rootNode){}
        T& operator*() const{return now->value;}
        T* operator->() const{return &(now->value);}
        Iterator& operator++() 
        {
            if(now) 
                now=findNext(now);
            return *this;
        }
        Iterator operator++(int) 
        {
            Iterator temp=*this;
            ++(*this);
            return temp;
        }
        Iterator& operator--() 
        {
            if(!now) 
                now=findMaxInSubtree(root);
            else 
                now=findPrev(now);
            return *this;
        }
        Iterator operator--(int) 
        {
            Iterator temp=*this;
            --(*this);
            return temp;
        }
        bool operator==(const Iterator& other) const{return now==other.now;}
        bool operator!=(const Iterator& other) const{return !(*this==other);}
        Iterator prev() const 
        {
            Iterator result=*this;
            --result;
            return result;
        }
        bool hasPrev() const 
        {
            if(!now)
                return root!=nullptr;
            return findPrev(now)!=nullptr;
        }
    };
    Iterator begin() const 
    {
        NodePtr minNode=root;
        while(minNode&&minNode->left) 
            minNode=minNode->left;
        return Iterator(minNode,root);
    }
    Iterator end() const{return Iterator(nullptr, root);}
    Iterator last() const 
    {
        NodePtr maxNode=root;
        while(maxNode&&maxNode->right) 
            maxNode=maxNode->right;
        return Iterator(maxNode,root);
    }
    Iterator find(const T& value) const 
    {
        NodePtr now=root;
        while(now) 
        {
            if(now->value==value) 
                return Iterator(now, root);
            else if(value<now->value) 
                now=now->left;
            else 
                now=now->right;
        }
        return end();
    }
    class ReverseIterator 
    {
    private:
        Iterator base_iterator;
    public:
        ReverseIterator(Iterator it):base_iterator(it){}
        T& operator*() const 
        {
            Iterator temp=base_iterator;
            --temp;
            return *temp;
        }
        T* operator->() const 
        {
            Iterator temp=base_iterator;
            --temp;
            return &(*temp);
        }
        ReverseIterator& operator++() 
        {
            --base_iterator;
            return *this;
        }
        ReverseIterator operator++(int) 
        {
            ReverseIterator temp=*this;
            --base_iterator;
            return temp;
        }
        ReverseIterator& operator--()
        {
            ++base_iterator;
            return *this;
        }
        ReverseIterator operator--(int) 
        {
            ReverseIterator temp=*this;
            ++base_iterator;
            return temp;
        }
        bool operator==(const ReverseIterator& other) const {return base_iterator==other.base_iterator;}
        bool operator!=(const ReverseIterator& other) const {return !(*this == other);}
        Iterator base() const {return base_iterator;}
    };
    ReverseIterator rbegin() const {return ReverseIterator(end());}
    ReverseIterator rend() const {return ReverseIterator(begin());}
};
int main() 
{
    Multiset<int> tril;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        tril.insert(n);
    }
    for(auto tmp:tril) cout<<tmp<<' ';
    return 0;   
}