#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> dis(202020,1e17),vis(202020,0),d(202020,0);
set<pair<int,int> > has;
vector<pair<int,int> > ed; 
map<pair<int,int>,int> eis;
struct edge
{
	int to,nxt,fl;
} e[1010100];
int head[2010101],cnt,ans;
inline void add(int u,int v)
{
	cnt++;
	e[cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
void dfs(int u)
{
	vis[u]=1;
	ans++;
	//cout<<"deleted node:"<<u<<endl;
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v=e[i].to;
        if(vis[v]==1) continue;
        if(!e[i].fl) continue;
        e[i].fl=0;
        d[v]--;
        if(d[v]==0) dfs(v);
    }
}
signed main()
{
	freopen("way2.in","r",stdin);
	freopen("way.out","w",stdout);
	ios::sync_with_stdio(0);
	int n,m,Q;
	cin>>n>>m>>Q;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		add(u,v);
		add(v,u);
		ed.push_back({u,v});
	}
	queue<int> q;
	q.push(1);
	dis[1]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].to;
			if(dis[v]==1e17||dis[v]==dis[u]+1) e[i].fl=1,dis[v]=dis[u]+1,eis[{u,v}]=1,d[v]++,has.insert({u,v});
			if(!vis[v]) q.push(v);
		}
	}
//	cout<<"has:\n";
//	for(pair<int,int> tmp:has) cout<<tmp.first<<' '<<tmp.second<<'\n';
//	cout<<"\n";
    for(int i=0;i<=n;i++) vis[i]=0;
	while(Q--)
	{
		int r;
		cin>>r;
//		cout<<"ans:";
		pair<int,int> ch=ed[r-1];
        if(has.find(ch)==has.end()) 
        {
            swap(ch.first,ch.second);
            if(has.find(ch)==has.end()) 
			{
				cout<<ans<<endl;
				continue;
			}
        }
        if(!eis[ch]) 
    	{
			cout<<ans<<endl;
			continue;
		}//cout<<"delete:"<<ch.first<<' '<<ch.second<<'\n';      
        eis[ch]=0;
        d[ch.second]--;
        if(d[ch.second]==0) dfs(ch.second);
        cout<<ans<<endl;
	}
	return 0;	
} 