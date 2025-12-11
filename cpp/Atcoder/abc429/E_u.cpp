#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

const int N=2e5+5;

struct node
{
    int nxt,to;
}e[N<<1];

int n,m,cnt;
string s;
int h[N],dis[N][2],f[N];

void add(int u,int v)
{
    cnt++;
    e[cnt].nxt=h[u];
    e[cnt].to=v;
    h[u]=cnt;
}

void dji()
{
    memset(dis,0x3f,sizeof(dis));
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    for(int u=1;u<=n;u++)
    {
        if(s[u]=='S')
            continue;
        for(int i=h[u];i!=0;i=e[i].nxt)
        {
            int v=e[i].to;
            if(s[v]=='S')
            {
                dis[u][1]=dis[u][0];
                dis[u][0]=1;
                q.push(make_pair(1,v));
            }
        }
    }
    while(!q.empty())
    {
        int d=q.top().first,u=q.top().second;
        q.pop();
        f[u]++;
        while(!q.empty()&&f[q.top().second]==2)
            q.pop();
        for(int i=h[u];i!=0;i=e[i].nxt)
        {
            int v=e[i].to;
            if(s[v]=='S'||f[v]==2)
                continue;
            if(dis[v][0]>d+1)
            {
                dis[v][1]=dis[v][0];
                dis[v][0]=d+1;
                q.push(make_pair(dis[v][0],v));
            }
            else if(dis[v][1]>d+1)
            {
                dis[v][1]=d+1;
                q.push(make_pair(dis[v][1],v));
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    cin>>s;
    s='#'+s;
    // cout<<s<<endl;
    dji();
    for(int i=1;i<=n;i++)
        if(s[i]=='D')
            cout<<dis[i][0]+dis[i][1]<<endl;
    return 0;
}