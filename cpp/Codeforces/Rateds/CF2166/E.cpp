#include <bits/stdc++.h>
using namespace std;

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
            if(l>r) return SIM;
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
#define int long long
namespace Qaaxaap
{
    using namespace DS;
    constexpr const int N = 5e5 + 5, MOD = 998244353;
    int T;
    inline void work()
    {
        cin>>T;
        while(T--) 
        {
            int n,q;
            cin>>n>>q;
            segment_tree_uni<int> trill(1,(1<<30)+5),dzdl(1,(1<<30)+5);
            for(int i=1;i<=n;i++) 
            {
                int tmp;
                cin>>tmp;
                trill.update(tmp,1);
                if(trill.query_sum(tmp)==1)dzdl.update(tmp,tmp);
            }
            while(q--)
            {
                int c;
                cin>>c;
                int num=-1;
                vector<int> nc;
                while(c)
                {
                    num++;
                    nc.push_back(c%2);
                    c>>=1;
                }
                int ans=0;
                vector<int> ys;
                for(int i=num;i>=0;i--)
                {
                    cout<<i<<endl;
                    if(!nc[i]) continue;
                    
                    int ql=dzdl.query_max(1,(1<<30));cout<<i<<endl;
                    if(ql<(1<<num)) ans+=((1<<i)-ql);
                    dzdl.update(ql,-ql);
                    ys.push_back(ql);
                }
                for(auto tmp:ys) dzdl.update(tmp,tmp);
                cout<<ans<<endl;
            }
        }
    }
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    return Qaaxaap::work(), 0;
}