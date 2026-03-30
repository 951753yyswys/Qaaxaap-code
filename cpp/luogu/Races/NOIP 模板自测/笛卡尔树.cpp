#include<bits/stdc++.h>
using namespace std;
namespace Qaaxaap
{
    using ll=long long;
    template<typename T>
    class FHQ
    {
    private:
        struct node
        {
            T val;
            ll pri;
            unique_ptr<node> ls,rs;
            node(int v,int p){val=v,pri=p;ls=nullptr;rs=nullptr;}
            node()=default;
            ~node()=default;
        };
        using uniT=unique_ptr<node>;
        uniT rt;
        uniT& merge(uniT& x,uniT& y)
        {
            if(x==nullptr) return y;
            if(y==nullptr) return x;
            if(x->pri<y->pri) 
            {
                if(x->val<y->val) x->rs=move(merge(x->rs,y));
                else x->ls=move(merge(x->ls,y));
                return x;
            }
            else 
            {
                if(y->val<x->val) y->rs=move(merge(y->rs,x));
                else y->ls=move(merge(y->ls,x));
                return y;
            }
        }
        void split(uniT& ro,int val,uniT& lrt,uniT &rrt)
        {
            if(ro==nullptr) 
            {
                lrt=nullptr;
                rrt=nullptr;
                return;
            }
            if(ro->val<val)
            {
                split(ro->rs,val,lrt,rrt);
                ro->rs=move(lrt);
                lrt=move(ro);
                return;
            }
            else 
            {
                split(ro->ls,val,lrt,rrt);
                ro->ls=move(rrt);
                rrt=move(ro);
                return;
            }
        }
        pair<ll,ll> _dfs(uniT& ro)
        {
            if(ro==nullptr) return {0,0};
            ll lt=0,rt=0;
            pair<ll,ll> ans,lans,rans;
            ans=lans=rans={0,0};
            if(ro->ls!=nullptr) lt=ro->ls->val;
            if(ro->rs!=nullptr) rt=ro->rs->val;
            if(ro->ls!=nullptr) lans=_dfs(ro->ls);
            if(ro->rs!=nullptr) rans=_dfs(ro->rs);
            ans={lans.first^rans.first,lans.second^rans.second};
            lt++,rt++;
            ans.first^=ro->val*lt;
            ans.second^=ro->val*rt;
            return ans;
        }
    public:
        void insert(T val,ll pri)
        {
            uniT rrt,lrt,nd=make_unique<node>(val,pri),tmp=nullptr;
            split(rt,val,lrt,rrt);
            tmp=move(merge(lrt,nd));
            lrt=move(tmp);
            rt=move(merge(lrt,rrt));
        }
        pair<ll,ll> dfs()
        {
            return _dfs(rt);
        }
    };
    const int N=5e5,mod=998244353;
    void work()
    {
        FHQ<int> t;
        int n,cnt=0;
        cin>>n;
        vector<int> p(n);
        for(auto& tmp:p) cin>>tmp,t.insert(++cnt,tmp);
        pair<ll,ll> ans=t.dfs();
        cout<<ans.first<<' '<<ans.second;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    return Qaaxaap::work(),0;
}