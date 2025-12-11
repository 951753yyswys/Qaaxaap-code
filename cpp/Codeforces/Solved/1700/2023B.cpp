#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge
{
    int to,nxt,w;
} e[1101010];
int head[1010100],cnt;
inline void add(int u,int v,int w)
{   
    cnt++;
    e[cnt].to=v;
    e[cnt].nxt=head[u];
    e[cnt].w=w;
    head[u]=cnt;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,cnt=0;
        cin>>n;
        vector<int> a(n+1),b(n+1),sum(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
        for(int i=1;i<=n+n;i++) head[i]=0;
        for(int i=1;i<=n;i++)
        {
            if(i!=1) add(i,i-1,0);
            if(b[i]>i) add(i,b[i],a[i]);
        }
        int ans=-1;
        vector<int> dis(n+1,0x7ffffffffffff),vis(n+1,0);
        dis[1]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,1});
        while(!q.empty())
        {
            int u=q.top().second;
            q.pop();
            if(vis[u]) continue;
            vis[u]=1;
            for(int i=head[u];i;i=e[i].nxt)
            {
                int v=e[i].to;
                if(dis[v]>dis[u]+e[i].w)
                {
                    dis[v]=dis[u]+e[i].w;
                    q.push({dis[v],v});
                }
            }
        }
        for(int i=1;i<=n;i++) 
        {
            if(dis[i]==0x7ffffffffffff) continue;
            ans=max(ans,sum[i]-dis[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
} 