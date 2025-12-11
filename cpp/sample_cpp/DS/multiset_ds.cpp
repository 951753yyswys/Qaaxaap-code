#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Multiset {
private:
    struct Node {
        T value;
        int priority;
        int size;
        Node* left;
        Node* right;
        Node* parent;
        
        Node(T val, Node* p = nullptr) 
            : value(val), priority(rand()), size(1), 
              left(nullptr), right(nullptr), parent(p) {}
    };
    
    using NodePtr = Node*;
    
    NodePtr root;
    vector<NodePtr> node_pool; // 节点池，用于析构时清理
    
    // 内联简单函数
    inline void updateSize(NodePtr node) {
        if(node) node->size = 1 + getSize(node->left) + getSize(node->right);
    }
    
    inline int getSize(NodePtr node) const {
        return node ? node->size : 0;
    }
    
    // 非递归的合并和分裂
    NodePtr merge(NodePtr left, NodePtr right) {
        if(!left) return right;
        if(!right) return left;
        
        if(left->priority > right->priority) {
            left->right = merge(left->right, right);
            if(left->right) left->right->parent = left;
            updateSize(left);
            return left;
        } else {
            right->left = merge(left, right->left);
            if(right->left) right->left->parent = right;
            updateSize(right);
            return right;
        }
    }
    
    void split(NodePtr node, const T& key, NodePtr& left, NodePtr& right) {
        if(!node) {
            left = right = nullptr;
            return;
        }
        if(node->value <= key) {
            left = node;
            split(node->right, key, left->right, right);
            if(left->right) left->right->parent = left;
            updateSize(left);
        } else {
            right = node;
            split(node->left, key, left, right->left);
            if(right->left) right->left->parent = right;
            updateSize(right);
        }
    }
    
    void splitStrict(NodePtr node, const T& key, NodePtr& left, NodePtr& right) {
        if(!node) {
            left = right = nullptr;
            return;
        }
        if(node->value < key) {
            left = node;
            splitStrict(node->right, key, left->right, right);
            if(left->right) left->right->parent = left;
            updateSize(left);
        } else {
            right = node;
            splitStrict(node->left, key, left, right->left);
            if(right->left) right->left->parent = right;
            updateSize(right);
        }
    }
    
    // 迭代版本的最小/最大值查找
    NodePtr findMin(NodePtr node) const {
        while(node && node->left) node = node->left;
        return node;
    }
    
    NodePtr findMax(NodePtr node) const {
        while(node && node->right) node = node->right;
        return node;
    }
    
public:
    Multiset() : root(nullptr) {}
    
    ~Multiset() {
        clear();
    }
    
    // 禁用拷贝构造和赋值
    Multiset(const Multiset&) = delete;
    Multiset& operator=(const Multiset&) = delete;
    
    void insert(const T& value) {
        NodePtr left, right;
        split(root, value, left, right);
        NodePtr newNode = new Node(value);
        node_pool.push_back(newNode);
        root = merge(merge(left, newNode), right);
    }
    
    void erase(const T& value) {
        NodePtr left, mid, right;
        splitStrict(root, value, left, mid);
        split(mid, value, mid, right);
        
        if(mid) {
            // 从节点池中移除并删除
            auto it = find(node_pool.begin(), node_pool.end(), mid);
            if(it != node_pool.end()) {
                node_pool.erase(it);
                delete mid;
            }
            mid = merge(mid->left, mid->right);
        }
        
        root = merge(merge(left, mid), right);
    }
    
    int count(const T& value) {
        NodePtr left, mid, right;
        splitStrict(root, value, left, mid);
        split(mid, value, mid, right);
        int cnt = getSize(mid);
        root = merge(merge(left, mid), right);
        return cnt;
    }
    
    void clear() {
        for(NodePtr node : node_pool) {
            delete node;
        }
        node_pool.clear();
        root = nullptr;
    }
    
    int size() const { return getSize(root); }
    bool empty() const { return !root; }
    
    class Iterator {
    private:
        NodePtr now;
        NodePtr root;
        
        NodePtr findNext(NodePtr node) const {
            if(!node) return nullptr;
            if(node->right) {
                NodePtr result = node->right;
                while(result->left) result = result->left;
                return result;
            }
            NodePtr parent = node->parent;
            while(parent && node == parent->right) {
                node = parent;
                parent = parent->parent;
            }
            return parent;
        }
        
        NodePtr findPrev(NodePtr node) const {
            if(!node) return nullptr;
            if(node->left) {
                NodePtr result = node->left;
                while(result->right) result = result->right;
                return result;
            }
            NodePtr parent = node->parent;
            while(parent && node == parent->left) {
                node = parent;
                parent = parent->parent;
            }
            return parent;
        }
        
        NodePtr findMaxInSubtree(NodePtr node) const {
            while(node && node->right) node = node->right;
            return node;
        }
        
    public:
        Iterator(NodePtr node = nullptr, NodePtr rootNode = nullptr) 
            : now(node), root(rootNode) {}
        
        T& operator*() const { return now->value; }
        T* operator->() const { return &(now->value); }
        
        Iterator& operator++() {
            if(now) now = findNext(now);
            return *this;
        }
        
        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }
        
        Iterator& operator--() {
            if(!now) now = findMaxInSubtree(root);
            else now = findPrev(now);
            return *this;
        }
        
        Iterator operator--(int) {
            Iterator temp = *this;
            --(*this);
            return temp;
        }
        
        bool operator==(const Iterator& other) const { return now == other.now; }
        bool operator!=(const Iterator& other) const { return now != other.now; } // 直接比较，避免函数调用
    };
    
    Iterator begin() const {
        return Iterator(findMin(root), root);
    }
    
    Iterator end() const { 
        return Iterator(nullptr, root); 
    }
    
    Iterator find(const T& value) const {
        NodePtr now = root;
        while(now) {
            if(now->value == value) return Iterator(now, root);
            else if(value < now->value) now = now->left;
            else now = now->right;
        }
        return end();
    }
};

int main() {
    Multiset<int> tril;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        tril.insert(n);
    }
    for(auto tmp : tril) cout << tmp << ' ';
    return 0;
}