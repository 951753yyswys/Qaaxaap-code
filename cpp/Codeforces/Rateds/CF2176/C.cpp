#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    void work()
    {
        int t;
        cin>>t;
        while(t--)
        {
            int n,mx=-1,cnt=0;
            cin>>n;
            vector<int> a(n),eve;
            for(auto &tmp:a)
            {
                cin>>tmp;
                if(tmp%2==1) mx=max(mx,tmp),cnt++;
                else eve.push_back(tmp);
            }
            if(eve.size()==0)
            {
                for(int i=1;i<=n;i++)
                {
                    if(i%2) cout<<mx<<' ';
                    else cout<<"0 ";
                }
                cout<<endl;
                continue;
            }
            sort(eve.rbegin(),eve.rend());
            // int ans=0;
            // if(eve.size()+1>=k)
            // {
            //     ans=mx;
            //     for(int i=0;i<k-1;i++) ans+=eve[i];
            //     cout<<ans<<endl;
            //     continue;
            // }
            // int odc=k-eve.size();
            // if(odc%2==1)
            // {
            //     ans=mx;
            //     for(auto tmp:eve) ans+=tmp;
            // }
            // else
            // {
            //     ans=mx;
            //     for(int i=0;i<eve.size()-1;i++) ans+=eve[i];
            // }
            // cout<<ans<<endl;
            if(mx==-1)
            {
                for(int i=1;i<=n;i++) cout<<"0 ";
                cout<<endl;
                continue;
            }
            int sum=0;
            cout<<mx<<' ';
            for(int i=2;i<=n;i++)
            {
                int ans=mx;
                if(eve.size()>i-2) sum+=eve[i-2];
                ans+=sum;
                if(eve.size()<=i-2) 
                {
                    int odc=i-eve.size();
                    if(odc%2==0) ans-=*prev(eve.end());
                    if(i==n&&cnt%2==0) ans=0;
                }
                cout<<ans<<' ';
            }
            cout<<endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    return Qaaxaap::work(),0;
} 