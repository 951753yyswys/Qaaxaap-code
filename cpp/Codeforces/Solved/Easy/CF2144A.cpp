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
        vector<int> a(n+1),sum(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) sum[i]=a[i]+sum[i-1],sum[i]%=3;
        int flag=0,ansl,ansr;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
            {
                int ls=sum[i];
                int ms=(sum[j]-sum[i]+3)%3;
                int rs=(sum[n]-sum[j]+3)%3;
                if(ls!=ms&&ms!=rs&&rs!=ls) 
                {
                    flag=1;
                    ansl=i;
                    ansr=j;
                    break;
                }
                if(ls==rs&&ms==ls)
                {
                    flag=1;
                    ansl=i;
                    ansr=j;
                    break;
                }
            }
        if(!flag) cout<<"0 0\n";
        else cout<<ansl-1<<' '<<ansr-1<<'\n';
    }
    return 0;
} 