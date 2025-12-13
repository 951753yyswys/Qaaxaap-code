#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    void work()
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        s='+'+s;
        deque<char> ans;
        bool del=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i]!='@'&&s[i]!='#') ans.push_back(s[i]+del*('A'-'a'));
            else
            {
                if(s[i]=='@') del^=1;
                else 
                {
                    if(!ans.empty()) ans.pop_back();
                }
            }
        }      
        while(!ans.empty())
        {
            cout<<ans.front();
            ans.pop_front();
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    return Qaaxaap::work(),0;
} 