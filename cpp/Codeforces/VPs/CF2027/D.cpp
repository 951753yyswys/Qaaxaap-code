#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
#include<stdlib.h>
#include<stdio.h>
#define int long long
using namespace std;

const int N=3e5+5;

int T,n,m;
int a[N],s[N],b[N],dp[N];
struct segment_tree
{
    struct node{long long l,r,sum,lazy_and,lazy_times,mi;};
    vector<node> t;int mod;
    inline void init(int n,int m){mod=m;t.resize(n*4+5);build(1,1,n);}
    void build(long long ro,long long l,long long r)
    {
        t[ro]={l,r,0,0,1,(int)1e18};
        if(l==r) return;
        long long mid=(l+r)/2;
        build(ro*2,l,mid);
        build(ro*2+1,mid+1,r);
        t[ro].sum=(t[ro*2].sum+t[ro*2+1].sum)%mod;
        t[ro].mi=min(t[ro*2].mi,t[ro*2+1].mi);
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
        t[ro].mi=min(t[ro*2].mi,t[ro*2+1].mi);
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
        t[ro].mi=min(t[ro*2].mi,t[ro*2+1].mi);
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
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            s[i]=s[i-1]+a[i];
        }
        for(int i=1;i<=m;i++)
            cin>>b[i];
        for(int i=1;i<=n;i++)
            dp[i]=1e18;
        for(int i=1;i<=m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int tem=upper_bound(s+1,s+n+1,s[j]+b[i])-s-1;
                dp[tem]=min(dp[tem],dp[j]+m-i);
            }
        }
        if(dp[n]!=1e18)
            cout<<dp[n]<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}