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
//         int n,cost=0;
//         cin>>n;
//         vector<int> a(n),b(n);
//         for(int i=0;i<n;i++) cin>>a[i];
//         for(int i=0;i<n;i++) cin>>b[i];
//         int flag=0;
//         for(int i=0;i<n;i++)
//         {
//             a[i]-=cost;
//             cost+=max(0ll,b[i]-a[i]);
//             if(a[i]<0)
//             {
//                 flag=1;
//                 break;
//             }
//         }
//         if(!flag) cout<<"yes\n";
//         else cout<<"no\n";
//     }
//     return 0;
// } 
// #include<bits/stdc++.h>
// #define int long long
// using namespace std;
// signed main() 
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int t;
//     cin>>t;
//     while(t--) 
//     {
//         int n;
//         cin>>n;
//         vector<int> a(n),b(n);
//         for(int i=0;i<n;i++) cin>>a[i];
//         for(int i=0;i<n;i++) cin>>b[i];
//         if(n==2) 
//         {
//             cout<<(a[0]+a[1]>=b[0]+b[1]?"YES":"NO")<<"\n";
//             continue;
//         }
//         int suma=0,sumb=0;
//         for(int i=0;i<n;i++) 
//         {
//             suma+=a[i];
//             sumb+=b[i];
//         }
//         if(suma<sumb) 
//         {
//             cout<<"NO\n";
//             continue;
//         }
//         bool flag=1;
//         for(int i=0;i<n;i++) 
//         {
//             if(b[i]>a[i]+(suma-sumb)) 
//             {
//                 flag=0;
//                 break;
//             }
//         }
//         cout<<(flag?"YES":"NO")<<"\n";
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
        int suma=0,sumb=0;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++) cin>>a[i],suma+=suma;
        for(int i=0;i<n;i++) cin>>b[i],sumb+=sumb;
        int delta=suma-sumb;
        if(delta<0)
        {
            cout<<"no\n";
            continue;
        }
        int cnt=0;
        for(int i=0;i<n;i++) if(a[i]<b[i]) cnt++;
        if(cnt>1)
        {
            cout<<"no\n";
            continue;
        }
        for(int i=0;i<n;i++)
        {
            if(a[i]<b[i])
            {
                int ds=b[i]-a[i];
                delta=ds;
            }
        }
        int flag=1;
        for(int i=0;i<n;i++)
        {
            if(a[i]<b[i]) continue;
            if(a[i]-delta<b[i]) 
            {
                flag=0;
                continue;
            }
        }
        if(flag) cout<<"yes\n";
        else cout<<"no\n";
    } 
    return 0;
} 