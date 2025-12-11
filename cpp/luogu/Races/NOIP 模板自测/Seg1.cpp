#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace DS
{
    using ll=long long;
    using ull=unsigned long long;
    template<typename T>
    class type 
    {
    public:
        T mi,mx,sum,len;
        type(){mi=mx=sum=len=T{};}
        type(T I,T X,T S,T L){mi=I,mx=X,sum=S,len=L;}
        void operator+=(const T& b){if(len!=0) mi+=b,mx+=b,sum+=b*len;}
        type operator+(const T& b) const{if(len==0) return type();return type(mi+b,mx+b,sum+b*len,len);}
        void operator+=(const type& b)
        {
            if(len==0) *this=b;
            else if(b.len==0) return;
            else mi=min(mi,b.mi),mx=max(mx,b.mx),sum+=b.sum,len+=b.len;
        }
        type operator+(const type& b) const
        {
            if(len==0) return type(b.mi,b.mx,b.sum,b.len);
            if(b.len==0) return type(mi,mx,sum,len);
            return type(min(mi,b.mi),max(mx,b.mx),sum+b.sum,len+b.len);
        }
    };
    template<typename T,class val>
    class seg
    {
        class node
        {
            int lt,rt,ls,rs;
            val num;
            node(){ls=rs=-1;}
        };
        vector<node> t;
        int size;
        inline void pushup(int ro)
        {
            if(t[ro].ls>=0) t[ro].num+=t[t[ro].ls].num;
            if(t[ro].rs>=0) t[ro].num+=t[t[ro].rs].num;
        }
        inline int newnode(int lt,int rt)
        {
            t.push_back(node());
            int ro=size;
            size++;
            t[ro].lt=lt;
            t[ro].rt=rt;
            return ro;
        }
        inline void pushdown(int ro)
        {
            if(t[ro].ls==0) 
            {
                
            }
        }
    };
}
namespace Qaaxaap
{
    const int N=5e5,mod=998244353;
    void work()
    {

    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    return Qaaxaap::work(),0;
}