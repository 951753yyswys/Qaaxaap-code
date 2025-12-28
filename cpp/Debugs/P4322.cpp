#include <bits/stdc++.h>
using namespace std;
#define N 2505
int k,n,fa[N],cnt;
double s[N], p[N], num[N], f[N][N],nxt[5003],e[5005],sz[N];
int hd[N];
void add(int u,int v) {
	e[cnt]=v,nxt[cnt]=hd[u],hd[u]=cnt++;
}
void dfs(int u,int fa) {
	sz[u]=1;
	f[u][1]=num[u];
	for (int i=hd[u];i!=-1;i=nxt[i]) {
		int v=e[i];
		if(v==fa)continue;
		dfs(v,u);
		for (int a=sz[u]; a>=1; --a) {
			for (int b=sz[v]; b>=1; --b) {
				f[u][a+b]=max(f[u][a+b],f[u][a]+f[v][b]);
			}
		}
		sz[u]+=sz[v];
	}
}
bool check(double mid) {
	for (int i=0; i<=n; ++i){
		num[i]=p[i]-mid*s[i],sz[i]=0;
		for (int j=1;j<=k+1;++j)
			f[i][j]=-1e18;
	}
	dfs(0,-1);
	return f[0][k+1]>0;
}
int main() {
	memset(hd,-1,sizeof hd); 
	//cout<<hd[0];
	cin>>k>>n;
	for (int i = 1; i <= n; ++i) {
		cin>>s[i]>>p[i]>>fa[i];
		add(fa[i],i);
	}
	double l=0,r=1000,mid;
	while (r-l>1e-5) {
		mid= l+(r-l)/2;
		if (check(mid)) l=mid;
		else r=mid;
	}
	cout<<fixed<<setprecision(3)<<l;
	return 0;
}

