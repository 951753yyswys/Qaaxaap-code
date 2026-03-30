#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1010101],b[1010101],c[1010101],head[1010101],cnt,n,mi[1010101],fa[1010101],z[1010101],in[1010101]; 
struct edge
    {int to,nxt;};
edge e[1010101];
inline void add(int u,int v)
{
    cnt++;
    e[cnt].to=v;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}
int tool(int u,int ans) 
{
    int l=1,r=n;
    int lzt=-1;
    while(l<=r) 
    {
        int mid=(l+r)>>1;
        __int128 sum=0;
        if(c[u]>=0)
            sum=(__int128)(ans-mid+1)*b[u]+(__int128)(mid+ans)*(ans-mid+1)/2*c[u];
        else 
        {
            if(mid>z[u]) 
                sum=ans-mid+1;
            else if(ans>z[u]) 
                sum=(__int128)(z[u]-mid+1)*b[u]+(__int128)(mid+z[u])*(z[u]-mid+1)/2*c[u]+(ans-z[u]);
            else 
                sum=(__int128)(ans-mid+1)*b[u]+(__int128)(mid+ans)*(ans-mid+1)/2*c[u];
        }
        if(sum>=a[u]) 
        {
            lzt=mid;
            l=mid+1;
        } 
        else 
            r=mid-1;
    }
    return lzt;
}

bool check(int x)
{
    for(int i=1;i<=n;i++)
    {
        mi[i]=tool(i,x);
        if(mi[i]<0) return 0;
    }
    
    vector<int> in_tmp(n+1,0);
    for(int i=1;i<=n;i++) 
        in_tmp[i]=in[i];
        
    priority_queue<pair<int,int>> q;
    for(int i=1;i<=n;i++)
        if(in_tmp[i]==0) 
            q.push({mi[i],i});
            
    vector<int> seq(n+1);
    for(int t=n;t>=1;t--)
    {
        if(q.empty()) return 0;
        int u=q.top().second;
        q.pop();
        seq[t]=u; 
        
        if(fa[u]!=0) 
        {
            in_tmp[fa[u]]--;
            if(in_tmp[fa[u]]==0) 
                q.push({mi[fa[u]],fa[u]});
        }
    } 
    
    for(int i=1;i<=n;i++)
        if(i>mi[seq[i]]) 
            return 0;
    return 1;
}

void dfs(int u,int f)
{
    fa[u]=f;
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==f) continue;
        dfs(v,u);
        in[u]++; 
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i]>>b[i]>>c[i];
        if(c[i]<0) 
            z[i]=(1-b[i])/c[i];
    }
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    dfs(1,0);
    int l=0,r=1e9,ans;
    while(l<=r)
    {
        int mid=l+r>>1;
        if(check(mid)) ans=mid,r=mid-1;
        else l=mid+1;
    }
    cout<<ans; 
    return 0;
}