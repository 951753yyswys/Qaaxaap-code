#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
int dp[5050][5050],sum[5050];
vector<int> col[5050];
struct edge
{
    int to,nxt;
} e[101010];
int head[101010],cnt;
inline void add(int u,int v)
{
    cnt++;
    e[cnt].to=v;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}
void dfs(int u,int f)
{
    for(auto tmp:col[u]) 
        dp[u][tmp]=1;
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==f) continue;
        dfs(v,u);
        for(auto tmp:col[u])
            dp[u][tmp]=dp[u][tmp]*((sum[v]-dp[v][tmp]+mod)%mod)%mod;
    }
    for(auto tmp:col[u]) sum[u]=(sum[u]+dp[u][tmp])%mod;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int ll;
        cin>>ll;
        while(ll--)
        {
            int tmp;
            cin>>tmp;
            col[i].push_back(tmp);
        }
    }
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    dfs(1,0);
    cout<<sum[1];
    return 0;
} 