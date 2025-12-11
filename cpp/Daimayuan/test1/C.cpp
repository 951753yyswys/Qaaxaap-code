#include<bits/stdc++.h>
using namespace std;
struct edge 
{
    int u, v, w, id;
};
class DSU 
{
private:
    vector<int> parent, rank;
public:
    DSU(int n):parent(n+1),rank(n+1,0){iota(parent.begin(),parent.end(),0);}
    int find(int x){return parent[x]==x?x:parent[x]=find(parent[x]);}
    bool unite(int x,int y) 
    {
        x=find(x),y=find(y);
        if(x==y) return 0;
        if(rank[x]<rank[y]) swap(x,y);
        parent[y]=x;
        if(rank[x]==rank[y]) rank[x]++;
        return 1;
    }
};
int main() 
{
    freopen("ex_a2.in","r",stdin);
    freopen("mamba.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    vector<edge> e(m);
    for(int i=0;i<m;i++) 
    {
        cin>>e[i].u>>e[i].v>>e[i].w;
        e[i].id=i;
    }
    sort(e.begin(),e.end(),[](const edge& a,const edge& b){return a.w>b.w;});
    vector<int> ans(m,0);
    vector<DSU> d(k+1,DSU(n));
    for(int i=0;i<m;i++) 
    {
        for(int r=1;r<=k;r++) if(d[r].unite(e[i].u,e[i].v)) 
        {
            ans[e[i].id]=r;
            break;
        }
    }
    for(auto tmp:ans) cout<<tmp<<endl;
    return 0;
}