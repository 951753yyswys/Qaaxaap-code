// // #include<bits/stdc++.h>
// // using namespace std;
// // #define int long long
// // struct segment_tree
// // {
// //     struct node{long long l,r,sum,lazy_and,lazy_times;};
// //     vector<node> t;int mod;
// //     inline void init(int n,int m){mod=m;t.resize(n*4+5);build(1,1,n);}
// //     void build(long long ro,long long l,long long r)
// //     {
// //         t[ro]={l,r,0,0,1};
// //         if(l==r) return;
// //         long long mid=(l+r)/2;
// //         build(ro*2,l,mid);
// //         build(ro*2+1,mid+1,r);
// //         t[ro].sum=(t[ro*2].sum+t[ro*2+1].sum)%mod;
// //     }
// //     inline void pushdown(long long ro)
// //     {
// //         long long ll=t[ro*2].r-t[ro*2].l+1;
// //         long long rl=t[ro*2+1].r-t[ro*2+1].l+1;
// //         t[ro*2].sum=(t[ro].lazy_times*t[ro*2].sum+t[ro].lazy_and*ll)%mod;
// //         t[ro*2+1].sum=(t[ro].lazy_times*t[ro*2+1].sum+t[ro].lazy_and*rl)%mod;
// //         t[ro*2].lazy_times=(t[ro].lazy_times*t[ro*2].lazy_times)%mod;
// //         t[ro*2+1].lazy_times=(t[ro].lazy_times*t[ro*2+1].lazy_times)%mod;
// //         t[ro*2].lazy_and=(t[ro*2].lazy_and*t[ro].lazy_times+t[ro].lazy_and)%mod;
// //         t[ro*2+1].lazy_and=(t[ro*2+1].lazy_and*t[ro].lazy_times+t[ro].lazy_and)%mod;
// //         t[ro].lazy_and=0;
// //         t[ro].lazy_times=1;
// //     }
// //     void update_times(long long ro,long long l,long long r,long long s)
// //     {
// //         if(t[ro].l>=l&&t[ro].r<=r)
// //         {
// //             t[ro].lazy_times=t[ro].lazy_times*s%mod;
// //             t[ro].sum=t[ro].sum*s%mod;
// //             t[ro].lazy_and=t[ro].lazy_and*s%mod;
// //             return;
// //         }
// //         pushdown(ro);
// //         if(t[ro*2].r>=l) update_times(ro*2,l,r,s);
// //         if(t[ro*2+1].l<=r) update_times(ro*2+1,l,r,s);
// //         t[ro].sum=(t[ro*2].sum+t[ro*2+1].sum)%mod;
// //     }
// //     void update_and(long long ro,long long l,long long r,long long s)
// //     {
// //         if(t[ro].l>=l&&t[ro].r<=r)
// //         {
// //             t[ro].lazy_and=(t[ro].lazy_and+s)%mod;
// //             t[ro].sum=(t[ro].sum+s*(t[ro].r-t[ro].l+1))%mod;
// //             return;
// //         }
// //         pushdown(ro);
// //         if(t[ro*2].r>=l) update_and(ro*2,l,r,s);
// //         if(t[ro*2+1].l<=r) update_and(ro*2+1,l,r,s);
// //         t[ro].sum=(t[ro*2].sum+t[ro*2+1].sum)%mod;
// //     }
// //     long long query(long long ro,long long l,long long r)
// //     {
// //         if(t[ro].l>=l&&t[ro].r<=r) return t[ro].sum;
// //         if(t[ro].r<l||t[ro].l>r) return 0;
// //         pushdown(ro);
// //         long long ans=0;
// //         if(t[ro*2].r>=l) ans=(ans+query(ro*2,l,r))%mod;
// //         if(t[ro*2+1].l<=r) ans=(ans+query(ro*2+1,l,r))%mod;
// //         return ans%mod;
// //     }
// //     inline void update_and(long long l,long long r,long long val){update_and(1,l,r,val);}
// //     inline void update_times(long long l,long long r,long long val){update_times(1,l,r,val);}
// //     inline long long query(long long l,long long r){return query(1,l,r);}
// // }tril; 
// // signed main()
// // {
// //     ios::sync_with_stdio(0);
// //     cin.tie(0),cout.tie(0);
// //     int t;
// //     cin>>t;
// //     while(t--)
// //     {
// //         int n,flag=1;
// //         cin>>n;
// //         tril.init(n,998244353);
// //         vector<int> cnt(n+1);
// //         for(int i=1;i<=n;i++)
// //         {
// //             int l;
// //             cin>>l;
// //             tril.update_times(l,l,0);            
// //             tril.update_and(l,n,1);
// //         }
// //         for(int i=1;i<=n;i++)
// //         {
// //             int cnt=tril.query(i,i);
// //             if(cnt>=3) 
// //             {
// //                 flag=0;
// //                 break;
// //             }
// //         }
// //         if(flag) cout<<"yes\n";
// //         else cout<<"no\n";
// //     }
// //     return 0;
// // } 
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// signed main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0),cout.tie(0);
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int n;
//         cin>>n;
//         vector<int> a(n);
//         for(auto &tmp:a) cin>>tmp;
//         int flag=1;
//         for(int i=1;i<n;i++)
//         {
//             if(a[i]<a[i-1]) 
//             {
//                 if(a[i-1]-a[i]!=1) 
//                 {
//                     flag=0;
//                     continue;
//                 }
//             }
//         }
//         if(flag) cout<<"yes\n";
//         else cout<<"No\n";
//     }
//     return 0;
// } 
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(auto &tmp:a) cin>>tmp;
        for(int i=1;i<n;i++)
        {
            if(a[i-1]>a[i]) 
            {
                if(a[i-1]-a[i]==1) swap(a[i-1],a[i]);
                else break;
            }
        }
        int flag=1;
        for(int i=0;i<n;i++) if(a[i]!=i+1) flag=0;
        if(flag) cout<<"yes\n";
        else cout<<"no\n";
    } 
    return 0;
} 