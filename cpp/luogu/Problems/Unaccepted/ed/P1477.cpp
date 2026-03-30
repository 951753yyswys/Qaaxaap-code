#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,mx;
const long long edge_num=1010100;
struct edge
{
    int to,nxt,w;
} e[edge_num];
int head[edge_num],cnt,dis[edge_num];
inline void add(int u,int v,int w)
{
    cnt++;
    e[cnt].to=v;
    e[cnt].nxt=head[u];
    e[cnt].w=w;
    head[u]=cnt;
}
void dfs(int u,int d)
{
    if(dis[u]==0x7ffffffffff) dis[u]=d;
    else
    {
        if(mx==0) mx= 
        mx=(mx,abs(d-dis[u]+2));
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) 
    {
        int a,b;
        cin>>a>>b;
        dis[i]=0x7ffffffffff;
    }
    return 0;
} 