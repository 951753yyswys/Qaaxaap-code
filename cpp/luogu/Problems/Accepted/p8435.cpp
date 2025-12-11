#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge
{
    int to,nxt;
} e[5010101];
int cnt,head[5010101],dfn[5010101],num,low[5010101],lst=-1;
stack<int> tr;
vector<vector<int>> ans;
inline void add(int u,int v)
{
    cnt++;
    e[cnt].to=v;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}
void dfs(int u,int f)
{
    dfn[u]=++num;
    low[u]=dfn[u];
    tr.push(u);
    int son=0;
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v=e[i].to;
        if(dfn[v])
        {
            if(v==f)
                continue;
            low[u]=min(low[u],dfn[v]);
            continue;
        }
        son++;
        dfs(v,u);
        low[u]=min(low[u],low[v]);
        if(low[v]>=dfn[u])
        {
            lst++;
            ans.push_back(vector<int>());
            while(!tr.empty())
            {
                ans[lst].push_back(tr.top());
                if(tr.top()==v)
                {
                    tr.pop();
                    break; 
                }
                tr.pop();
            }
            ans[lst].push_back(u);
        }
    }
    if(son==0&&f==0) 
    {
        lst++;
        ans.push_back(vector<int>());
        ans[lst].push_back(u);
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    for(int i=1;i<=n;i++) 
        if(!dfn[i])
        {
            dfs(i,0);
            while(!tr.empty()) 
                tr.pop();
        }
    cout<<lst+1<<endl;
    for(auto tmp1:ans)
    {
        cout<<tmp1.size()<<' ';
        for(auto tmp2:tmp1)
            cout<<tmp2<<' '; 
        cout<<endl;
    }
    return 0;
}