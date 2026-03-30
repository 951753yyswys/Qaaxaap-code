#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge
{
    int to,nxt;
} e[1010100];
int head[1010100],cnt,dep[1010100],mdep,siz[1010100],d[1010100],flag,n;
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
    d[u]=0;
    dep[u]=dep[f]+1;
    if(u==n) d[u]=1;
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==f) continue;
        dfs(v,u);
        d[u]=max(d[u],d[v]);
    }
}
bool cmp(pair<int,int> x,pair<int,int> y)
{
    if(x.second!=y.second) return x.second>y.second;
    return x.first<y.first;
}
bool cmp1(pair<int,int> x,pair<int,int> y)
{
    if(x.second!=y.second) return x.second<y.second;
    return x.first>y.first;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=cnt;i++) e[i]={0,0};
        for(int i=1;i<=n;i++) head[i]=dep[i]=siz[i]=d[i]=0;
        cnt=mdep=flag=0;
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            add(u,v);
            add(v,u);
        }
        dfs(1,0);
        vector<pair<int,int>> del,ans;
        int now=1;
        for(int i=1;i<=n;i++)
        {
            if(d[i]) continue;
            del.push_back({i,dep[i]});
        }
        sort(del.begin(),del.end(),cmp);
        for(auto ro:del)
        {
            int de=ro.second;
            int u=ro.first;
            if(now%2==de%2) 
            {
                ans.push_back({1,0});
                ans.push_back({2,u});
                now++;
            }
            else 
            {
                ans.push_back({1,0});
                ans.push_back({1,0});
                ans.push_back({2,u});
                now+=2;
            }
        }
        del.clear();
        for(int i=1;i<n;i++)
        {
            if(!d[i]) continue;
            del.push_back({i,dep[i]});
        }
        sort(del.begin(),del.end(),cmp1);
        for(auto ro:del)
        {
            int de=ro.second;
            int u=ro.first;
            if(now%2==de%2) 
            {
                ans.push_back({1,0});
                ans.push_back({2,u});
                now++;
            }
            else 
            {
                ans.push_back({1,0});
                ans.push_back({1,0});
                ans.push_back({2,u});
                now+=2;
            }
        }
        cout<<ans.size()<<endl;
        for(auto tmp:ans)
        {
            cout<<tmp.first;
            if(tmp.first==2) cout<<' '<<tmp.second;
            cout<<endl;
        }
    }
    return 0;
} 