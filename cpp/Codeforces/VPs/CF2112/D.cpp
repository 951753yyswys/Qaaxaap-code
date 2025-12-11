#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge
{
    int to,nxt;
} e[1010100];
int head[1010100],cnt,dep[1010100],mdep,siz[1010100],d[1010100],color[1010100],flag;
vector<pair<int,int>> ans;
void add(int u,int v)
{
    cnt++;
    e[cnt].to=v;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}
void dfs(int u,int f)
{
    // dep[u]=dep[f]+1;
    // siz[u]=1;
    // int son=0,lson=0;
    // mdep=max(dep[u],mdep);
    // for(int i=head[u];i;i=e[i].nxt)
    // {
    //     int v=e[i].to;
    //     if(v==f) continue;
    //     if(dep[u]%2) ans.push_back({v,u});
    //     else ans.push_back({u,v});
    //     dfs(v,u);
    //     siz[u]+=siz[v];
    //     son++;
    //     lson=v;
    //     if(siz[lson]==2&&flag==0)
    //     {
    //     flag=1;
    //     swap((*prev(ans.end())).first,(*prev(ans.end())).second);
    //     } 
    // }
    if(color[u]==3)
    {
        int cntt=0;
        for(int i=head[u];i;i=e[i].nxt)
        {
            int v=e[i].to;
            if(v==f) continue;
            color[v]=++cntt;
            dfs(v,u);
        }
        return;
    }
    else
    {
        if(color[u]==1) ans.push_back({u,f});
        else ans.push_back({f,u});
        for(int i=head[u];i;i=e[i].nxt)
        {
            int v=e[i].to;
            if(v==f) continue;
            color[v]=3-color[u];
            dfs(v,u);
        }
    }
}
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
        if(n==2) 
        {
            int lll;
            cin>>lll;
            cin>>lll;
            cout<<"no\n";
            continue;
        }
        ans.clear();
        for(int i=1;i<=cnt;i++) e[i]={0,0};
        for(int i=1;i<=n;i++) head[i]=dep[i]=siz[i]=d[i]=color[i]=0;
        cnt=mdep=flag=0;
        int root=-1;
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            add(u,v);
            add(v,u);
            d[u]++;
            d[v]++;
        }
        for(int i=1;i<=n;i++) if(d[i]==2) root=i;
        if(root==-1)
        {
            cout<<"No\n";
            continue;
        }
        color[root]=3;
        dfs(root,0);
        cout<<"yes\n";
        for(auto tmp:ans) cout<<tmp.first<<' '<<tmp.second<<'\n';
        //vector<int>
    }
    return 0;
} 