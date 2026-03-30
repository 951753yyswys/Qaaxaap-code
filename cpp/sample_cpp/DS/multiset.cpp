#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>
class multiset_
{
private:
    int cnt=0,root=0;
    struct tree{T num;int l,r,pri,siz;};
    vector<tree> t;
    inline int init(T num){t.push_back({T{},0,0,0,0}),t[++cnt]={num,0,0,rand(),1};return cnt;}
    inline void pushup(int ro){t[ro].siz=t[t[ro].l].siz+t[t[ro].r].siz+1;}
    int merge(int lt,int rt)
    {
        if(lt==0||rt==0) return max(lt,rt);
        if(t[lt].pri<t[rt].pri){t[lt].r=merge(t[lt].r,rt);pushup(t[lt].r);return lt;}
        else{t[rt].l=merge(lt,t[rt].l);pushup(t[rt].l);return rt;}
    }
    void split_val(int ro,T k,int &lt,int &rt)
    {
        if(!ro) return void(lt=rt=0);
        if(t[ro].num<=k){lt=ro;split_val(t[ro].r,k,t[ro].r,rt);}
        else{rt=ro;split_val(t[ro].l,k,lt,t[ro].l);}
        pushup(ro);
    }
    void split_val_y(int ro,T k,int &lt,int &rt)
    {
        if(!ro) return void(lt=rt=0);
        if(t[ro].num<k){lt=ro;split_val_y(t[ro].r,k,t[ro].r,rt);}
        else{rt=ro;split_val_y(t[ro].l,k,lt,t[ro].l);}
        pushup(ro);
    }
    void split_rnk(int ro,int k,int &lt,int &rt)
    {
        if(!ro) return void(lt=rt=0);
        if(t[t[ro].l].siz<k){lt=ro;split_rnk(t[ro].r,k-t[t[ro].l].siz-1,t[ro].r,rt);}
        else{rt=ro;split_rnk(t[ro].l,k,lt,t[ro].l);}
        pushup(ro);
    }
    void add(T x)
    {
        int ro=init(x),lt,rt;
        split_val(root,x,lt,rt);
        root=merge(merge(lt,ro),rt);
    }
    T query_val_front(T v)
    {
        int lt,rt;split_val_y(root,v,lt,rt);
        int lr=lt;
        T qm=T{};
        while(lr!=0) qm=max(qm,t[lr].num),lr=t[lr].r;
        root=merge(lt,rt);
        return qm;
    }
    T query_val_back(T v)
    {
        int lt,rt;split_val(root,v,lt,rt);
        int lr=rt;
        T qm=T{};
        while(lr!=0) qm=t[lr].num,lr=t[lr].l;
        root=merge(lt,rt);
        return qm;
    }
    void delt(T x)
    {
        int lt,rt,mlt,mrt;
        split_val_y(root,x,lt,rt);
        split_rnk(rt,1,mlt,mrt);
        root=merge(lt,mrt);
    }
    T query_rnk_to_val(T rk)
    {
        int lt,rt;split_rnk(root,rk,lt,rt);
        int num=0,ro=lt;
        while(ro!=0) num=t[ro].num,ro=t[ro].r;
        root=merge(lt,rt);
        return num;
    }
    int query_val_to_rnk(T val)
    {
        int lt,rt;split_val_y(root,val,lt,rt);
        int num=t[lt].siz+1;
        root=merge(lt,rt);
        return num;
    }
    int query_val_to_rnk_y(T val)
    {
        int lt,rt;split_val(root,val,lt,rt);
        int num=t[lt].siz+1;
        root=merge(lt,rt);
        return num;
    }
public:
    multiset_(){for(int i=1;i<=5;i++) t.push_back({T{},0,0,0,0});}
    void insert(T num){add(num);}
    int count(T num)
    {
        int cnt1,cnt2;
        cnt1=query_val_to_rnk(num);
        cnt2=query_val_to_rnk_y(num);
        return -cnt1+cnt2;
    }
    T upper_bound(T num)
    {
        T yk=num;
        while(yk==num) num=query_val_back(num);
        return num;
    }
    T lower_bound(T num)
    {
        T yk=num;
        num=query_val_back(num);
        if(num!=T{}) return num;
        return yk;
    }
    int size(){return t[root].siz;}
};
signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    multiset_<string> tril;
    while(t--)
    {
        int opt=0;
        cin>>opt;
        if(opt==1) 
        {
            string s;
            cin>>s;
            tril.insert(s);
            cout<<"over\n";
        }
        if(opt==2)
        {
            string s;
            cin>>s;
            cout<<tril.count(s);
        }
        if(opt==3)
        {
            string s;
            cin>>s;
            cout<<tril.lower_bound(s);
        }
        //vector<int>
    }
    return 0;
} 