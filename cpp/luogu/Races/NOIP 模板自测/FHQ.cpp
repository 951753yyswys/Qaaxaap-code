#include<bits/stdc++.h>
using namespace std;
namespace DS
{
    using ll=long long;
    using ull=unsigned long long;
    template<typename T>
    class FHQ
    {
    private:

        int Tsize=0;
        struct node
        {
            T val;
            ull pri,siz;
            unique_ptr<node> ls,rs;
            node(T v){val=v,pri=rand();ls=nullptr,rs=nullptr;}
            ~node()=default;    
        };
        using uniT=unique_ptr<node>;
        uniT rt;
        void pushup(uniT& x)
        {
            if(x==nullptr) return;
            x->siz=1;
            if(x->ls!=nullptr) x->siz+=x->ls->siz;
            if(x->rs!=nullptr) x->siz+=x->rs->siz;
            return;
        }
        uniT& merge(uniT& x,uniT& y)
        {
            if(x==nullptr) return y;
            if(y==nullptr) return x;
            if(x->pri>y->pri)
            {
                if(x->val<y->val) x->rs=move(merge(x->rs,y));
                else x->ls=move(merge(x->ls,y));
                pushup(x);
                return x;
            }
            else
            {
                if(y->val<x->val) y->rs=move(merge(y->rs,x));
                else y->ls=move(merge(y->ls,x));
                pushup(y);  
                return y;
            }
        }
        void split(uniT& ro,int val,uniT& lrt,uniT& rrt)
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
                pushup(ro);
                lrt=move(ro);
            }
            else 
            {
                split(ro->ls,val,lrt,rrt);
                ro->ls=move(rrt);
                pushup(ro);
                rrt=move(ro);
            }
        }
        void splitf(uniT& ro,int val,uniT& lrt,uniT& rrt)
        {
            if(ro==nullptr)
            {
                lrt=nullptr;
                rrt=nullptr;
                return;
            }
            if(ro->val<=val)
            {
                splitf(ro->rs,val,lrt,rrt);
                ro->rs=move(lrt);
                pushup(ro);
                lrt=move(ro);
            }
            else 
            {
                splitf(ro->ls,val,lrt,rrt);
                ro->ls=move(rrt);
                pushup(ro);
                rrt=move(ro);
            }
        }
        void splitr(uniT& ro,int rank,uniT& lrt,uniT& rrt)
        {
            if(ro==nullptr)
            {
                lrt=nullptr;
                rrt=nullptr;
                return;
            }
            if(ro->siz<=rank)
            {
                splitr(ro->rs,rank,lrt,rrt);
                ro->rs=move(lrt);
                pushup(ro);
                lrt=move(ro);
            }
            else 
            {
                splitr(ro->ls,rank-ro->ls->siz-1,lrt,rrt);
                ro->ls=move(rrt);
                pushup(ro);
                rrt=move(ro);
            }
        }
        void _insert(T x)
        {
            uniT lrt,rrt,tmp,hd=make_unique<node>(x);
            split(rt,x,lrt,rrt);
            tmp=move(merge(lrt,hd));
            lrt=move(tmp);
            rt=move(merge(lrt,rrt));
            Tsize++;
        }
        void _remove(T x)
        {
            uniT lrt,rrt,mrt,tmp;
            split(rt,x,lrt,mrt);
            splitr(mrt,1,tmp,rrt);
            rt=move(merge(lrt,rrt));
            Tsize--;
        }
        ll _query_rank(T val)
        {
            uniT lrt,rrt;
            split(rt,val,lrt,rrt);
            ll rnk=lrt->siz+1;
            rt=move(merge(lrt,rrt));
            return rnk;
        }
        T _query_val(ll rnk) 
        {
            uniT lrt, rrt;
            splitr(rt,rnk-1,lrt,rrt);
            T val=T{};
            if(rrt!=nullptr) 
            {
                node** now=&(rrt.get());
                while(*now->ls!=nullptr) 
                    now=&(*now->ls.get());
                val=*now->val;
            }
            rt=move(merge(lrt,rrt));
            return val;
        }
        T _prev(T val)
        {
            uniT lrt,rrt;
            split(rt,val,lrt,rrt);
            T ret=T{};
            node* now=lrt.get();
            while(now!=nullptr)
            {
                ret=now->val;
                now=now->rs.get();
            }
            rt=move(merge(lrt,rrt));
            return ret;
        }
        T _next(T val)
        {
            uniT lrt,rrt;
            splitf(rt,val,lrt,rrt);
            T ret=T{};
            node* now=rrt.get();
            while(now!=nullptr)
            {
                ret=now->val;
                now=now->ls.get();
            }
            rt=move(merge(lrt,rrt));
            return ret;
        }
    public:
        FHQ(){srand(time(NULL)+clock());};
        ~FHQ()=default;
        void insert(T x){_insert(x);}
        void remove(T x){_remove(x);}
        ll query_rank(T x){return _query_rank(x);}
        T query_val(ll rk){return _query_val(rk);}
        T prev(T x){return _prev(x);}
        T next(T x){return _next(x);}
        void clear(){rt.reset();};
    };
    
}
using namespace DS;
namespace Qaaxaap
{
    const int N=5e5,mod=998244353;
    void work()
    {
        using ll=long long;
        ll n;
        cin>>n;
        FHQ<ll> tr;
        while(n--)
        {
            ll opt,x;
            cin>>opt>>x;
            if(opt==1) tr.insert(x);
            if(opt==2) tr.remove(x);
            if(opt==3) cout<<tr.query_rank(x)<<endl;
            if(opt==4) cout<<tr.query_val(x)<<endl;
            if(opt==5) cout<<tr.prev(x)<<endl;
            if(opt==6) cout<<tr.next(x)<<endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    return Qaaxaap::work(),0;
}