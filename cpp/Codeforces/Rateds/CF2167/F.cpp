#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) 
    {
        int n,k;
        cin>>n>>k;
        vector<vector<int>> mp(n + 1);
        for(int i=1;i<n;i++) 
        {
            int u,v;
            cin>>u>>v;
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<int> fa(n+1,-1),sz(n+1,0),ord;
        stack<int> st;
        st.push(1);
        fa[1]=-1;
        while(!st.empty()) 
        {
            int u=st.top();
            st.pop();
            ord.push_back(u);
            for(int v:mp[u]) 
            {
                if (v==fa[u]) 
                    continue;
                fa[v]=u;
                st.push(v);
            }
        }
        for(int i=ord.size()-1;i>=0;i--) 
        {
            int u=ord[i];
            sz[u]=1;
            for(auto v:mp[u]) 
            {
                if(v==fa[u]) 
                    continue;
                sz[u]+=sz[v];
            }
        }
        int ans=0;
        for(int v=1;v<=n;v++) 
        {
            long long cnt=1;
            for(auto u:mp[v]) 
            {
                int s;
                if(u==fa[v])
                    s=n-sz[v];
                else 
                    s=sz[u];
                if(n-s>=k) 
                    cnt+=s;
            }
            ans+=cnt;
        }
        cout<<ans<<endl;
    }
    return 0;
}