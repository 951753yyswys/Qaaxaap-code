#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    const int N=5e5,mod=998244353;
    int cnt=0,head[N],low[N],dfn[N],num=0,lst=0,co[N],vc[N];
    class edge
    {
    public:
        int to,nxt;
        edge()=default;
        ~edge()=default;
    } e[N];
    inline void add(int u,int v)
    {
        cnt++;
        e[cnt].to=v;
        e[cnt].nxt=head[u];
        head[u]=cnt;
    }
    stack<int> st;
    vector<vector<int>> ans;
    void tarjan(int u)
    {
        if(dfn[u]) return;
        dfn[u]=++num;
        low[u]=dfn[u];
        st.push(u);
        for(int i=head[u];i;i=e[i].nxt)
        {
            int v=e[i].to;
            if(dfn[v])
            {
                low[u]=min(low[u],dfn[v]);
                continue;
            }
            tarjan(v);
            low[u]=min(low[v],low[u]);
        }
        if(low[u]==dfn[u])
        {
            ans.push_back(vector<int>());
            while(!st.empty())
            {
                ans[lst].push_back(st.top());
                co[st.top()]=lst;
                if(st.top()==u)
                {
                    st.pop();
                    break;
                }
                st.pop();
            }
            lst++;
        }
    }
    void work()
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
            int u,v;
            cin>>u>>v;
            add(u,v);
        }   
        for(int i=1;i<=n;i++) tarjan(i);
        cout<<lst<<endl;
        for(int i=1;i<=n;i++)
        {
            if(vc[co[i]]) continue;
            vc[co[i]]=1;
            sort(ans[co[i]].begin(),ans[co[i]].end());
            for(auto tmp:ans[co[i]]) cout<<tmp<<' ';
            cout<<endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    return Qaaxaap::work(),0;
}