#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge
{
	int to,nxt;
} e[500010];
int head[500010],cnt,ans,son,sl[500050],num[500010];
inline void add(int u,int v)
{
	cnt++;
	e[cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
int check(int u,int f)
{
	int sum=0;
	for(int i=head[u];i!=0&&sum<=1;i=e[i].nxt)
	{
		int v=e[i].to;
		if(f!=v) sum++;
	}
	return sum;
}
void dfs1(int u,int f)
{
	num[u]=1;
	sl[u]=0;
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v!=f)  
		{
			num[u]++;
			if(!check(v,u)) sl[u]++,son++;
			dfs1(v,u);
		}
	}
}
void dfs2(int u,int f)
{
	ans=max(ans,sl[u]);
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v!=f) dfs2(v,u);
	}
}
signed main()
{
	for(int ii=1;ii<=20;ii++)
	{
		string inn="lct"+to_string(ii)+".in";
		string outt="lct"+to_string(ii)+".out";
		freopen(inn.c_str(),"r",stdin);
		freopen(outt.c_str(),"w",stdout);
		int t;
		cin>>t;
		while(t--)
		{
			int n;
			cin>>n;	
			cnt=ans=son=0;
			for(int i=0;i<=2*n;i++) head[i]=0,e[i]={0,0},num[i]=0,sl[i]=0; 
			for(int i=1;i<n;i++)
			{
				int u,v;
				cin>>u>>v;
				add(u,v);
				add(v,u);
			}									
			if(n==2) {cout<<"0\n";continue;}
			dfs1(1,0);
			if(check(1,0)==1) 
			{
				son++;
				for(int i=head[1];i;i=e[i].nxt) 
				{
					int v=e[i].to;
					if(v!=0) sl[v]++;
				}
			}
			dfs2(1,0);
			cout<<son-ans<<endl;
		}
	}
	return 0;
}

