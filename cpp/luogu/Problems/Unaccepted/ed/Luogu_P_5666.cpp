#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pir pair<long long,long long>
struct edge
{
    int to,nxt;
} e[1010101];
int head[1010101],cnt,top[1010101],son[1010101],siz[1010101],fa[1010101],dfn[1010101],num,nson[1010101],hd[1010101];
inline void add(int u,int v)
{
    cnt++;
    e[cnt].to=v;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}
void dfs1(int u,int f)
{
    fa[u]=f;
    siz[u]=1;
    son[u]=-1;
    nson[u]=-1;
    int mx=0;
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==f) 
            continue;
        dfs1(v,u);
        siz[u]+=siz[v];
        if(siz[v]>=mx)
        {
            mx=siz[v];
            nson[u]=son[u];
            son[u]=v;
        }
        else
        {
            if(siz[v]>=nson[u]) 
                nson[u]=v;
        }
    }
}
void dfs2(int u,int t)
{
    top[u]=t;
    dfn[++num]=u;
    if(son[u]!=-1) 
        dfs2(son[u],t);
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa[u]||v==son[u]) 
            continue;
        dfs2(v,v);
    }
}
void dsu(int u)
{
    if(son[u]!=-1) dsu(u);
	else 
	{
		hd[u]=u;
		return;
	}
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa[u]||v==son[u]) 
            continue;	
		dsu(v);
    }        
	int g=hd[u];

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
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            add(u,v);
            add(v,u);
        }
        //vector<int>
    }
    return 0;
} 
