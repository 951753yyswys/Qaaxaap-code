#include<bits/stdc++.h>
using namespace std;
struct segment_tree
{
    long long mod;
    struct node{long long l,r,sum,lazy_and,lazy_times;} t[2000001];
    void build(long long ro,long long l,long long r)
    {
        t[ro]={l,r,0,0,1};
        if(l==r) return;
        long long mid=(l+r)/2;
        build(ro*2,l,mid);
        build(ro*2+1,mid+1,r);
        t[ro].sum=(t[ro*2].sum+t[ro*2+1].sum)%mod;
    }
    inline void init(long long siz,long long m){mod=m;build(1,1,siz);}
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
} tril;
int main()//luogu p3373
{
    int n,q,m;
    cin>>n>>q>>m;
    tril.init(n+2,m);
    for(int i=1;i<=n;i++){int l;cin>>l;tril.update_and(i,i,l);}
    while(q--)
    {
        int opt,x,y,k;cin>>opt>>x>>y;
        if(opt==1) cin>>k,tril.update_times(x,y,k);
        if(opt==2) cin>>k,tril.update_and(x,y,k);
        if(opt==3) cout<<tril.query(x,y)<<endl;
    }
}