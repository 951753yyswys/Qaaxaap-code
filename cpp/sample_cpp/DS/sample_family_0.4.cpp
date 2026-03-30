#include<bits/stdc++.h>
using namespace std;
struct treap
{
    long long cnt=0,root=0;
    struct tree{long long num,l,r,pri,siz;};
    vector<tree> t;
    treap(){for(int i=1;i<=5;i++) t.push_back({0,0,0,0,0});}
    inline long long init(long long num){t.push_back({0,0,0,0,0}),t[++cnt]={num,0,0,rand(),1};return cnt;}
    inline void pushup(long long ro){t[ro].siz=t[t[ro].l].siz+t[t[ro].r].siz+1;}
    long long merge(long long lt,long long rt)
    {
        if(lt==0||rt==0) return max(lt,rt);
        if(t[lt].pri<t[rt].pri){t[lt].r=merge(t[lt].r,rt);pushup(t[lt].r);return lt;}
        else{t[rt].l=merge(lt,t[rt].l);pushup(t[rt].l);return rt;}
    }
    void split_val(long long ro,long long k,long long &lt,long long &rt)
    {
        if(!ro) return void(lt=rt=0);
        if(t[ro].num<=k){lt=ro;split_val(t[ro].r,k,t[ro].r,rt);}
        else{rt=ro;split_val(t[ro].l,k,lt,t[ro].l);}
        pushup(ro);
    }
    void split_rnk(long long ro,long long k,long long &lt,long long &rt)
    {
        if(!ro) return void(lt=rt=0);
        if(t[t[ro].l].siz<k){lt=ro;split_rnk(t[ro].r,k-t[t[ro].l].siz-1,t[ro].r,rt);}
        else{rt=ro;split_rnk(t[ro].l,k,lt,t[ro].l);}
        pushup(ro);
    }
    void add(long long x)
    {
        long long ro=init(x),lt,rt;
        split_val(root,x,lt,rt);
        root=merge(merge(lt,ro),rt);
    }
    long long query_val_front(long long v)
    {
        long long lt,rt;split_val(root,v-1,lt,rt);
        long long lr=lt,qm=-0x7fffffff;
        while(lr!=0) qm=max(qm,t[lr].num),lr=t[lr].r;
        root=merge(lt,rt);
        return qm;
    }
    long long query_val_back(long long v)
    {
        long long lt,rt;split_val(root,v,lt,rt);
        long long lr=rt,qm=0x7fffffff;
        while(lr!=0) qm=min(qm,t[lr].num),lr=t[lr].l;
        root=merge(lt,rt);
        return qm;
    }
    void delt(long long x)
    {
        long long lt,rt,mlt,mrt;
        split_val(root,x-1,lt,rt);
        split_rnk(rt,1,mlt,mrt);
        root=merge(lt,mrt);
    }
    long long query_rnk_to_val(long long rk)
    {
        long long lt,rt;split_rnk(root,rk,lt,rt);
        long long num=0,ro=lt;
        while(ro!=0) num=t[ro].num,ro=t[ro].r;
        root=merge(lt,rt);
        return num;
    }
    long long query_val_to_rnk(long long val)
    {
        long long lt,rt;split_val(root,val-1,lt,rt);
        long long num=t[lt].siz+1;
        root=merge(lt,rt);
        return num;
    }
};
struct segment_tree
{
    struct node{long long l,r,sum,lazy_and,lazy_times;};
    vector<node> t;int mod;
    inline void init(int n,int m){mod=m;t.resize(n*4+5);build(1,1,n);}
    void build(long long ro,long long l,long long r)
    {
        t[ro]={l,r,0,0,1};
        if(l==r) return;
        long long mid=(l+r)/2;
        build(ro*2,l,mid);
        build(ro*2+1,mid+1,r);
        t[ro].sum=(t[ro*2].sum+t[ro*2+1].sum)%mod;
    }
    inline void pushdown(long long ro)
    {
        long long ll=t[ro*2].r-t[ro*2].l+1;
        long long rl=t[ro*2+1].r-t[ro*2+1].l+1;
        t[ro*2].sum=(t[ro].lazy_times*t[ro*2].sum+t[ro].lazy_and*ll)%mod;
        t[ro*2+1].sum=(t[ro].lazy_times*t[ro*2+1].sum+t[ro].lazy_and*rl)%mod;
        t[ro*2].lazy_times=(t[ro].lazy_times*t[ro*2].lazy_times)%mod;
        t[ro*2+1].lazy_times=(t[ro].lazy_times*t[ro*2+1].lazy_times)%mod;
        t[ro*2].lazy_and=(t[ro*2].lazy_and*t[ro].lazy_times+t[ro].lazy_and)%mod;
        t[ro*2+1].lazy_and=(t[ro*2+1].lazy_and*t[ro].lazy_times+t[ro].lazy_and)%mod;
        t[ro].lazy_and=0;
        t[ro].lazy_times=1;
    }
    void update_times(long long ro,long long l,long long r,long long s)
    {
        if(t[ro].l>=l&&t[ro].r<=r)
        {
            t[ro].lazy_times=t[ro].lazy_times*s%mod;
            t[ro].sum=t[ro].sum*s%mod;
            t[ro].lazy_and=t[ro].lazy_and*s%mod;
            return;
        }
        pushdown(ro);
        if(t[ro*2].r>=l) update_times(ro*2,l,r,s);
        if(t[ro*2+1].l<=r) update_times(ro*2+1,l,r,s);
        t[ro].sum=(t[ro*2].sum+t[ro*2+1].sum)%mod;
    }
    void update_and(long long ro,long long l,long long r,long long s)
    {
        if(t[ro].l>=l&&t[ro].r<=r)
        {
            t[ro].lazy_and=(t[ro].lazy_and+s)%mod;
            t[ro].sum=(t[ro].sum+s*(t[ro].r-t[ro].l+1))%mod;
            return;
        }
        pushdown(ro);
        if(t[ro*2].r>=l) update_and(ro*2,l,r,s);
        if(t[ro*2+1].l<=r) update_and(ro*2+1,l,r,s);
        t[ro].sum=(t[ro*2].sum+t[ro*2+1].sum)%mod;
    }
    long long query(long long ro,long long l,long long r)
    {
        if(t[ro].l>=l&&t[ro].r<=r) return t[ro].sum;
        if(t[ro].r<l||t[ro].l>r) return 0;
        pushdown(ro);
        long long ans=0;
        if(t[ro*2].r>=l) ans=(ans+query(ro*2,l,r))%mod;
        if(t[ro*2+1].l<=r) ans=(ans+query(ro*2+1,l,r))%mod;
        return ans%mod;
    }
    inline void update_and(long long l,long long r,long long val){update_and(1,l,r,val);}
    inline void update_times(long long l,long long r,long long val){update_times(1,l,r,val);}
    inline long long query(long long l,long long r){return query(1,l,r);}
}; 
struct fenwick_tree
{
    vector<long long> t;int n;
    inline long long lowbit(long long x){return x&(-x);}
    inline void init(long long x){t.resize(x+5);n=x+2;}
    inline void add(long long pl,long long val){while(pl<=n){t[pl]+=val,pl+=lowbit(pl);}}
    inline long long query(long long pl){long long sum=0;while(pl>0){sum+=t[pl],pl-=lowbit(pl);}return sum;}
};
namespace DS
{
    template<typename T>
    class segment_tree_uni
    {
    private:
        T MIN,MAX,SIM;
        struct tree
        {
            unique_ptr<tree> ls,rs;
            int num,lt,rt;
            T mi,mx,sum,lz;
            tree(T I,T A,T S){ls=nullptr,rs=nullptr,num=1,mi=A,mx=I,sum=lz=S;lt=rt=0;}
            ~tree()=default;
        };
        using uniT=unique_ptr<tree>;
        uniT root;
        uniT& gls(uniT& ro)
        {
            if(ro->ls==nullptr) 
            {
                ro->ls=make_unique<tree>(MIN,MAX,SIM);
                int mid=ro->lt+ro->rt>>1;
                ro->ls->lt=ro->lt;
                ro->ls->rt=mid;
            }
            return ro->ls;
        }
        uniT& grs(uniT& ro)
        {
            if(ro->rs==nullptr) 
            {
                ro->rs=make_unique<tree>(MIN,MAX,SIM);
                int mid=ro->lt+ro->rt>>1;
                ro->rs->lt=mid+1;
                ro->rs->rt=ro->rt;
            }
            return ro->rs;
        }
        void pushup(uniT& ro)
        {
            if(ro==nullptr) return;
            ro->num=1,ro->sum=SIM,ro->mi=MAX,ro->mx=MIN;
            if(ro->ls!=nullptr)
            {
                ro->num+=ro->ls->num;
                ro->sum+=ro->ls->sum;
                ro->mi=min(ro->mi,ro->ls->mi);
                ro->mx=max(ro->mx,ro->ls->mx);
            }
            if(ro->rs!=nullptr)
            {
                ro->num+=ro->rs->num;
                ro->sum+=ro->rs->sum;
                ro->mi=min(ro->mi,ro->rs->mi);
                ro->mx=max(ro->mx,ro->rs->mx);
            }
        }
        void pushdown(uniT& ro)
        {
            if(ro->lt==ro->rt) return;
            if(ro==nullptr) return;
            if(ro->lz==SIM) return;
            auto& ls=gls(ro);
            auto& rs=grs(ro);
            int sizl=ls->rt-ls->lt+1;
            int sizr=rs->rt-rs->lt+1;
            ls->sum+=ro->lz*sizl;
            rs->sum+=ro->lz*sizr;
            ls->mi+=ro->lz;
            ls->mx+=ro->lz;
            rs->mi+=ro->lz;
            rs->mx+=ro->lz;
            ls->lz+=ro->lz;
            rs->lz+=ro->lz;
            ro->lz=SIM;
        }
        void update(uniT& ro,int l,int r,T val)
        {
            if(ro->lt>=l&&ro->rt<=r) 
            {
                ro->sum+=val*(ro->rt-ro->lt+1);
                ro->mi+=val;
                ro->mx+=val;
                ro->lz+=val;
                return;
            }
            pushdown(ro);
            int mid=ro->lt+ro->rt>>1;
            if(l<=mid) update(gls(ro),l,r,val);
            if(r>mid) update(grs(ro),l,r,val);
            pushup(ro);
        }
        void update(uniT& ro,int pl,T val)
        {
            if(ro->rt==ro->lt) 
            {
                ro->sum+=val;
                ro->mi+=val;
                ro->mx+=val;
                return;
            }
            pushdown(ro);
            int mid=ro->lt+ro->rt>>1;
            if(pl<=mid) update(gls(ro),pl,val);
            else update(grs(ro),pl,val);
            pushup(ro);
        }
        T query_sum(uniT& ro,int l,int r)
        {
            if(ro->lt>=l&&ro->rt<=r) return ro->sum;
            pushdown(ro);
            T tmp=SIM;
            int mid=ro->lt+ro->rt>>1;
            if(l<=mid) tmp+=query_sum(gls(ro),l,r);
            if(r>mid) tmp+=query_sum(grs(ro),l,r);
            return tmp;
        }
        T query_sum(uniT& ro,int pl)
        {
            if(ro->lt==ro->rt) return ro->sum;
            pushdown(ro);
            int mid=ro->lt+ro->rt>>1;
            if(pl<=mid) return query_sum(gls(ro),pl);
            else return query_sum(grs(ro),pl);
        }
        T query_min(uniT& ro,int l,int r)
        {
            if(ro->lt>=l&&ro->rt<=r) return ro->mi;
            pushdown(ro);
            T tmp=MAX;
            int mid=ro->lt+ro->rt>>1;
            if(l<=mid) tmp=min(tmp,query_min(gls(ro),l,r));
            if(r>mid) tmp=min(tmp,query_min(grs(ro),l,r));
            if(tmp==MAX||tmp==MIN) tmp=SIM;
            return tmp;
        }
        T query_max(uniT& ro,int l,int r)
        {
            if(ro->lt>=l&&ro->rt<=r) return ro->mx;
            pushdown(ro);
            T tmp=MIN;
            int mid=ro->lt+ro->rt>>1;
            if(l<=mid) tmp=max(tmp,query_max(gls(ro),l,r));
            if(r>mid) tmp=max(tmp,query_max(grs(ro),l,r));
            if(tmp==MAX||tmp==MIN) tmp=SIM;
            return tmp;
        }
        int tree_size(){return root->num;}
        void erase(uniT& ro,int l,int r)
        {
            int mid=ro->lt+ro->rt>>1;
            if(ro->ls!=nullptr)
            {
                if(ro->ls->rt<=r&&ro->ls->lt>=l) ro->ls.reset();
                else erase(ro->ls,l,r);    
            }
            if(ro->rs!=nullptr)
            {
                if(ro->rs->rt<=r&&ro->rs->lt>=l) ro->rs.reset();
                else erase(ro->rs,l,r);
            }
            pushup(ro);
        }
    public:
        segment_tree_uni()
        {
            uniT tmp;
            MIN=-1e9;
            MAX=1e9;
            SIM=0;
            tmp=make_unique<tree>(MIN,MAX,SIM);
            tmp->lt=1;
            tmp->rt=1e7;
            root=move(tmp);
        }
        segment_tree_uni(int l,int r)
        {
            uniT tmp;
            MIN=-1e9;
            MAX=1e9;
            SIM=0;
            tmp=make_unique<tree>(MIN,MAX,SIM);
            tmp->lt=l;
            tmp->rt=r;
            root=move(tmp);
        }
        segment_tree_uni(int l,int r,T val_min,T val_max,T val_simple)
        {
            uniT tmp;
            MIN=val_min;
            MAX=val_max;
            SIM=val_simple;
            tmp=make_unique<tree>(MIN,MAX,SIM);
            tmp->lt=l;
            tmp->rt=r;
            root=move(tmp);
        }
        T query_sum(int l,int r)
        {
            if(l==r) return query_sum(root,l);
            else return query_sum(root,l,r);
        }
        T query_sum(int pl){return query_sum(root,pl);}
        T query_min(int l,int r)
        {
            if(l==r) return query_sum(root,l);
            else return query_min(root,l,r);
        }
        T query_max(int l,int r)
        {
            if(l==r) return query_sum(root,l);
            else return query_max(root,l,r);
        }
        void update(int l,int r,T val)
        {
            if(l==r) update(root,l,val);
            else update(root,l,r,val);
        }
        void update(int pl,T val){update(root,pl,val);}
        int size(){return tree_size();}
        void erase(int l,int r){erase(root,l,r);}
        void erase()
        {
            int l=root->lt,r=root->rt;
            uniT tmp;
            tmp=make_unique<tree>(MIN,MAX,SIM);
            tmp->lt=l;
            tmp->rt=r;
            root=move(tmp);
        }
    };
};
using namespace DS;
int main()
{
    return 0;
}