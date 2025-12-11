#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge
{
    int to,nxt;
} e[5010101];
int cnt,head[5010101],tv[5010101],dfn[5010101],num,low[5010101],lst=-1,d[5010101],ret[5010101];
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
    if(dfn[u])
        return;
    tr.push(u);
    dfn[u]=++num;
    low[u]=dfn[u];
    tv[u]=1;
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==f) 
        {
            if(!ret[v]) 
            {
                ret[v]=1;
                continue;
            }
        }
        if(dfn[v])
        {
            if(!tv[v]) 
                continue;
            low[u]=min(low[u],dfn[v]);
            continue;
        }
        dfs(v,u);
        low[u]=min(low[u],low[v]);
    }
    ret[f]=0;
    if(low[u]==dfn[u])
    {
        lst++;
        ans.push_back(vector<int>());
        while(!tr.empty()&&dfn[tr.top()]>=dfn[u])
        {
            ans[lst].push_back(tr.top());
            tv[tr.top()]=0;
            tr.pop();
        }
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
        d[u]++;
        d[v]++;
    }
    for(int i=1;i<=n;i++) dfs(i,0);
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