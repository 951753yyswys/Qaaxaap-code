#include<bits/stdc++.h>
#define int long long
#define map unordered_map
using namespace std;
namespace luuia {const int __SIZE=(1<<21)+1;
char ibuf[__SIZE],*iS,*iT,obuf[__SIZE],*oS=obuf,*oT=oS+__SIZE-1,_c,qu[55];int __f,qr,_eof;
#define Gc()(iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,__SIZE,stdin),(iS==iT?EOF:*iS++)):*iS++)
inline void flush(){fwrite(obuf,1,oS-obuf,stdout),oS=obuf;}inline void gc(char &x){x=Gc();}
inline void pc(char x){*oS++=x;if(oS==oT)flush();}
inline void pstr(const char *s){int __len=strlen(s);for(__f = 0;__f< __len;++__f)pc(s[__f]);}
inline void gstr(char *s){for(_c=Gc();_c<32||_c>126||_c==' ';)_c=Gc();
for(;_c>31&&_c<127&&_c!=' '&&_c!='\n'&&_c!='\r';++s,_c=Gc())*s=_c;*s=0;}
template<class I>inline bool read(I &x){_eof=0;
for(__f=1,_c=Gc();(_c<'0'||_c>'9')&&!_eof;_c=Gc()){if(_c=='-')__f=-1;_eof|=_c==EOF;}
for(x=0;_c<='9'&&_c>='0'&&!_eof;_c=Gc())x=x*10+(_c&15),_eof|=_c==EOF;x*=__f;return !_eof;}
template<class I>inline void print(I x){if(!x)pc('0');if(x<0)pc('-'),x=-x;
while(x)qu[++qr]=x%10+'0',x/= 10;while(qr)pc(qu[qr--]);}struct Flusher_{~Flusher_(){flush();}}io_flusher_;
}using luuia::pc;using luuia::gc;using luuia::pstr;using luuia::gstr;using luuia::read;using luuia::print;
namespace Qaaxaap
{
    const int mod=998244353;
    const int md=86;
    int n,m;
    vector<int> a;
    vector<vector<int>> adj;
    vector<map<int,vector<int>>> vtn;
    vector<map<int,int>> mem;
    vector<int> vis;
    int dfs(int u,int v,int dep) 
    {
        if(dep>md) return 0;  
        if(mem[u].count(v)) return mem[u][v];
        int cnt=0;
        int need=a[u]+a[v];
        if(need>(int)1e18) 
        {
            mem[u][v]=0;
            return 0;
        }
        auto it=vtn[v].find(need);
        if(it!=vtn[v].end()) for(int w:it->second) if(!vis[w])  
        {
            vis[w]=1;
            cnt=(cnt+1+dfs(v,w,dep+1))%mod;
            vis[w]=0;
        }
        mem[u][v]=cnt;
        return cnt;
    }
    void work()
    {
        int t;
        read(t);
        while(t--)
        {
            read(n);
            read(m);
            a.resize(n+1);
            for(int i=1;i<=n;i++) read(a[i]);
            adj.resize(n+1);
            for(auto &tmp:adj) tmp=vector<int>();
            for(int i=1;i<=m;i++) 
            {
                int u,v;
                read(u);
                read(v);
                adj[u].push_back(v);
            }
            vtn.resize(n+1);
            for(auto &tmp:vtn) tmp=map<int,vector<int>>();
            for(int u=1;u<=n;u++) for(int v:adj[u]) vtn[u][a[v]].push_back(v);
            mem.resize(n+1);
            vis.resize(n+1);
            for(auto &tmp:mem) tmp=map<int,int>();
            int ans=m%mod;  
            for(int u=1;u<=n;u++) for(int v:adj[u])
            {
                vis[u]=1;
                vis[v]=1;
                ans=(ans+dfs(u,v,2))%mod;
                vis[u]=0;
                vis[v]=0;
            }        
            print(ans),pc('\n');
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    return Qaaxaap::work(),0;
} 