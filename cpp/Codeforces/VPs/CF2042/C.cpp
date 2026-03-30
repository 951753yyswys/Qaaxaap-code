#include<bits/stdc++.h>
using namespace std;
#define int long long
struct fenwick_tree
{
    vector<long long> t;int n;
    inline long long lowbit(long long x){return x&(-x);}
    inline void init(long long x){t.resize(x+5);n=x+2;}
    inline void add(long long pl,long long val){while(pl<=n){t[pl]+=val,pl+=lowbit(pl);}}
    inline long long query(long long pl){long long sum=0;while(pl>0){sum+=t[pl],pl-=lowbit(pl);}return sum;}
};
bool cmp(int x,int y)
{
    return x>y;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        int num=0,cnt=0;
        cin>>n>>k;
        string temp;
        cin>>temp;
        vector<int> a(n),sum(n,0);
        for(int i=0;i<n;i++) 
        {
            if(temp[i]=='1') a[i]=1;
            else a[i]=-1;
        }
        sum[n-1]=a[n-1];
        for(int i=n-2;i>0;i--) sum[i]=a[i]+sum[i+1];
        sort(sum.begin(),sum.end(),cmp);
        for(int i=0;i<n;i++) 
        {
            if(sum[i]<=0) break;
            num+=sum[i];
            cnt++;
            if(num>=k) break;
        }
        if(num<k) cout<<-1<<endl;
        else cout<<cnt+1<<endl;
    }
    return 0;
} 