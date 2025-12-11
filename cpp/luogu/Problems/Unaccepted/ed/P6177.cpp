#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    const int N=5e4+5,mod=998244353;
    using ll=long long;
    int siz[N],fa[N],dfn[N],top[N],son[N],cnt=0,dep[N],val[N],bucl[N],cntl=-1;
    vector<line> lll;
    void dfs1(int u,int f,vector<vector<int>> &g)
    {
        int mx=0;
        dep[u]=dep[f]+1;
        son[u]=-1;
        fa[u]=f;
        siz[u]=1;
        for(auto v:g[u])
        {
            if(v==f) continue;
            dfs1(v,u,g);
            siz[u]+=siz[v];
            if(siz[v]>mx)
            {
                son[u]=v;
                mx=siz[v];
            }
        }
    }
    void dfs2(int u,int tp,vector<vector<int>> &g)
    {
        dfn[u]=++cnt;
        top[u]=tp;
        if(son[u]!=-1) dfs2(son[u],tp,g);
        for(auto v:g[u])
        {
            if(v==fa[u]||v==son[u]) continue;
            dfs2(v,v,g);
        }
        if(g[u].size()==1)
        {
            cntl++;
            bucl[top[u]]=cntl;
            lll.push_back(line(dfn[u]-dfn[tp]+1));
            lll[cntl].init(dfn[tp],dfn[u]);
        }
    }
    int lca(int x,int y)
    {
        while(top[x]!=top[y])
        {
            if(dep[top[x]]<dep[top[y]]) swap(x,y);
            x=fa[top[x]];
        }
        if(dep[x]<dep[y]) return x;
        else return y;
    }
    class line
    {
    private:
        vector<int> belong,sum;
        vector<bitset<40005>> ksum;
        vector<vector<bitset<40005>>> st;
        int klong,knum,num,start,kb;
        int getl(int k){return klong*(k-1)+1;}
        int getr(int k){return klong*k;}
    public:
        line(int n)
        {
            num=n;
            klong=sqrt(n)+1;
            belong.resize(n+1);
            sum.resize(n+1);            
            for(int i=1;i<=n;i++) belong[i]=1+(i-1)/klong;
            knum=belong[n];
            kb=__lg(knum)+1;
            st.resize(kb+1);
            ksum.resize(knum+1);
            for(int i=0;i<=kb;i++) st[i].resize(knum+1);
        }
        void init(int l)
        {
            start=l;
            for(int i=1;i<=num;i++) sum[i]=val[dfn[i+l-1]];
            for(int k=1;k<=knum;k++) for(int i=getl(k);i<=getr(k);i++) ksum[k][val[i]]=1;
            for(int i=1;i<=knum;i++) st[0][i]=ksum[i];
            for(int b=1;b<=kb;b++)
            {
                int len=1<<b;
                int lst=len>>1;
                for(int i=1;i+len-1<=knum;i++) st[b][i]=st[b-1][i]|st[b-1][i+lst];
            }
        }
        bitset<40005> query_st(int l,int r)
        {
            int len=r-l+1;
            int b=__lg(len);
            int stlen=1<<b;
            return st[b][l]|st[b][r-stlen+1];
        }
        bitset<40005> query(int l,int r)
        {
            l=l-start+1;
            r=r-start+1;
            bitset<40005> ans;
            while(l!=getl(belong[l])) ans[val[l]]=1,l++;
            if(r==getr(belong[r])) ans|=query_st(belong[l],belong[r]);
            else 
            {
                if(belong[l]!=belong[r]) ans|=query_st(l,r);
                while(r!=getl(belong[r])) ans[val[r]]=1,r++;
            }
            return ans;
        }
    };
    int query(int x,int y)
    {
        bitset<40005> ans;
        while(top[x]!=top[y])
        {

        }
    }
    void work()
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> g(n+1);
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        } 
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    return Qaaxaap::work(),0;
}