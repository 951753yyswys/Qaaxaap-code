#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    const int N=5e5,mod=998244353;
    void work()
    {
        int t;
        cin>>t;
        while(t--)
        {
            int n,m,k;
            cin>>n>>k>>m;
            string s;
            cin>>s;
            int cnt=0;
            set<char> alm;
            vector<char> ans;
            for(int i=0;i<m;i++) 
            {
                alm.insert(s[i]);
                if(alm.size()==k)
                {
                    alm.clear();
                    ans.push_back(s[i]);
                    cnt++;
                }
            }
            if(cnt>=n)
            {
                cout<<"Yes"<<endl;
                continue;
            }
            cout<<"No"<<endl;
            char ed='0';
            for(char i='a';i<k+'a';i++) if(!alm.count(i)) ed=i;
            for(auto tmp:ans) cout<<tmp;
            for(int i=cnt+1;i<=n;i++) cout<<ed;
            cout<<endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    return Qaaxaap::work(),0;
}