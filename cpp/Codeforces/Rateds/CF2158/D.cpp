#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    const int N=5e5,mod=998244353,kmin=4,kmax=7;
    vector<int> pst[kmax+1],opl[kmax+1],opr[kmax+1];
    bool hw(int sti,int l,int r) 
    {
        while(l<r) 
        {
            int b1=(sti>>l)&1;
            int b2=(sti>>r)&1;
            if(b1!=b2) return 0;
            ++l,--r;
        }
        return 1;
    }
    int fz(int sti,int l,int r) 
    {
        for(int i=l;i<=r;i++) sti^=(1<<i);
        return sti;
    }
    void init(int len) 
    {
        int tot=1<<len;
        pst[len].assign(tot,-1);
        opl[len].assign(tot,-1);
        opr[len].assign(tot,-1);
        vector<int> dt(tot,-1);
        queue<int> q;
        int str=0;
        dt[str]=0;
        pst[len][str]=str;
        q.push(str);
        while(!q.empty()) 
        {
            int now=q.front(); 
            q.pop();
            for(int l=0;l<len;l++) for(int r=l+1;r<len;r++) 
            {
                if(!hw(now,l,r)) continue;
                int nb=fz(now,l,r);
                if(dt[nb]==-1) 
                {
                    dt[nb]=dt[now]+1;
                    pst[len][nb]=now;
                    opl[len][nb]=l;
                    opr[len][nb]=r;
                    q.push(nb);
                }
            }
        }
    }
    vector<int> split(int n) 
    {
        vector<bool> dp(n+1);
        vector<int> pre(n+1,-1);
        dp[0]=1;
        for(int i=1;i<=n;i++) for(int len=kmin;len<=kmax;len++) 
        {
            if(i>=len&&dp[i-len]) 
            {
                dp[i]=1;
                pre[i]=len;
                break;
            }
        }
        vector<int> segs;
        int now=n;
        while(now>0) 
        {
            int len=pre[now];
            segs.push_back(len);
            now-=len;
        }
        reverse(segs.begin(),segs.end());
        return segs;
    }
    int ti(string &s,int L,int R) 
    {
        int sti=0;
        for(int i=L;i<=R;i++) if(s[i]=='1') sti|=(1<<(i-L));
        return sti;
    }
    void opt(string &s,int l,int r) 
    {
        --l;--r; 
        for(int i=l;i<=r;i++) s[i]=(s[i]=='0'?'1':'0');
    }
    void work()
    {
        for(int len=kmin;len<=kmax;len++) init(len);
        int T;
        cin>>T;
        while(T--) 
        {
            int n;
            string s,t;
            cin>>n>>s>>t;
            string now=s;
            vector<pair<int,int>> ops;
            vector<int> segs=split(n);
            int pos=0; 
            for(int slen:segs) 
            {
                int L=pos;
                int R=pos+slen-1;
                pos+=slen;
                int len=slen;
                int ms=ti(now,L,R);
                int mt=ti(t,L,R);
                if(ms==mt) continue; 
                auto &par=pst[len];
                auto &pl=opl[len];
                auto &pr=opr[len];
                int m=ms;
                {
                    vector<pair<int,int>> seq;
                    while(m!=0) 
                    {
                        int p=par[m];
                        int l=pl[m];
                        int r=pr[m];
                        seq.push_back({L+l+1,L+r+1});
                        m=p;
                    }
                    for(auto &op:seq) 
                    {
                        opt(now,op.first,op.second);
                        ops.push_back(op);
                    }
                }
                {
                    int m=mt;
                    vector<pair<int,int>> seq;
                    while(m!=0) 
                    {
                        int p=par[m];
                        int l=pl[m];
                        int r=pr[m];
                        seq.push_back({L+l+1,L+r+1});
                        m=p;
                    }
                    for(int i=seq.size()-1;i>=0;i--) 
                    {
                        auto op=seq[i];
                        opt(now,op.first,op.second);
                        ops.push_back(op);
                    }
                }
            }
            cout<<ops.size()<<endl;
            for(auto [l,r]:ops) cout<<l<<" "<<r<<endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    return Qaaxaap::work(),0;
}