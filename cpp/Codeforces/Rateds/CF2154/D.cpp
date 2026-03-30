#include<bits/stdc++.h>
using namespace std;
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while (t--) 
    {
        int n;
        cin>>n;
        vector<vector<int>> edge(n+1);
        for(int i=0;i<n-1;i++) 
        {
            int u,v;
            cin>>u>>v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        vector<int> fa(n+1,-1);
        queue<int> q;
        q.push(n);
        fa[n]=0;
        while(!q.empty()) 
        {
            int u=q.front();
            q.pop();
            for(int v:edge[u]) 
            {
                if(fa[v]==-1) 
                {
                    fa[v]=u;
                    q.push(v);
                }
            }
        }
        vector<int> path;
        int cur=1;
        while(cur!=0) 
        {
            path.push_back(cur);
            cur=fa[cur];
        }
        vector<string> ans;
        for(int i=0;i<path.size()-1;i++) 
        {
            int u=path[i];
            int p=path[i+1];
            vector<int> brk;
            for(int v:edge[u]) 
                if(v!=p) 
                    brk.push_back(v);
            if(brk.empty())
                ans.push_back("1");
            else 
            {
                for(int j=0;j<brk.size();j++) 
                {
                    ans.push_back("2 "+to_string(brk[j]));
                    if(j<brk.size()-1)
                    {
                        ans.push_back("1");
                        ans.push_back("1");
                    } 
                    else 
                        ans.push_back("1");
                }
            }
        }
        cout<<ans.size()<<"\n";
        for(const string& s:ans)
            cout<<s<<"\n";
    }
    return 0;
}