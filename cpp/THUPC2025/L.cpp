#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    const int MOD=1e9+7;
    vector<int> P;
    int ssm(int l,int r)
    {
        return (P[r]-P[l]+MOD)%MOD;
    }
    void work()
    {
        int n,q;
        cin>>n>>q;
        vector<int> a(n);
        for(auto &tmp:a) cin>>tmp,tmp%=MOD;
        sort(a.begin(),a.end(),greater<int>());
        P.resize(n+1);
        for(int i=0;i<n;i++) P[i+1]=(P[i]+a[i])%MOD;
        vector<int> inv(n+1),invsq(n+1);
        inv[1]=1;
        for(int i=2;i<=n;i++) inv[i]=MOD-(MOD/i)*inv[MOD%i]%MOD;
        for(int i=1;i<=n;i++) invsq[i]=inv[i]*inv[i]%MOD;
        const int bls=2000;
        vector<vector<int>> yans(bls+1);
        for(int l=1;l<=bls;l++) 
        {
            int g=n/l;
            int rem=n-g*l;
            vector<int> pref(g+1,0);
            for(int j=0;j<g;j++) 
            {
                int lt=j*l;
                int rt=lt+l;
                int s=ssm(lt,rt);
                int val=((s*s)%MOD*invsq[l])%MOD;
                pref[j+1]=(pref[j]+val)%MOD;
            }
            if(rem==0) 
            {
                yans[l]={pref[g]};
                continue;
            }
            vector<int> ans(rem+1,-1);
            ans[0]=-1;
            for(int rt=1;rt<=rem;rt++) 
            {
                if(rem>g*rt) 
                {
                    ans[rt]=-1;
                    continue;
                }
                int x=rem/rt;
                int y=rem%rt;
                int tmp=g-x-(bool)(y>0);
                int now=pref[tmp];
                int opt=tmp*l;
                if(y>0) 
                {
                    int sz=l+y;
                    int s=ssm(opt,opt+sz);
                    now=(now+((s*s)%MOD*invsq[sz])%MOD)%MOD;
                    opt+=sz;
                }
                if(x>0) 
                {
                    int sz=l+rt;
                    int invk=invsq[sz];
                    for(int t=0;t<x;t++) 
                    {
                        int s=ssm(opt,opt+sz);
                        now=(now+((s*s)%MOD*invk)%MOD)%MOD;
                        opt+=sz;
                    }
                }
                ans[rt]=now;
            }
            yans[l]=move(ans);
        }
        vector<int> lq(q),rq(q);
        for(int i=0;i<q;i++) 
        {
            cin>>lq[i];
            cin>>rq[i];
        }
        vector<int> lans(q,-1);
        vector<int> bi;
        for(int i=0;i<q;i++) 
        {
            int l=lq[i],r=rq[i];
            if(l<=bls) 
            {
                int g=n/l;
                int rem=n-g*l;
                if(n>g*r) 
                {
                    lans[i]=-1;
                    continue;
                }
                if(rem==0) 
                {
                    lans[i]=yans[l][0];
                    continue;
                }
                if(r==l) 
                { 
                    lans[i]=-1; 
                    continue; 
                }
                int rt=r-l;
                int t=min(rt,rem);
                lans[i]=yans[l][t]; 
            } 
            else bi.push_back(i);
        }
        sort(bi.begin(),bi.end(),[&](int i,int j){return lq[i]<lq[j];});
        int opt1=0;
        while(opt1<bi.size()) 
        {
            int idx0=bi[opt1];
            int l=lq[idx0];
            int g=n/l;
            int rem=n-g*l;
            vector<int> pref(g+1,0);
            for(int j=0;j<g;j++) 
            {
                int lt=j*l;
                int rt=lt+l;
                int s=ssm(lt,rt);
                int val=((s*s)%MOD*invsq[l])%MOD;
                pref[j+1]=(pref[j]+val)%MOD;
            }
            int opt2=opt1;
            while(opt2<bi.size()&&lq[bi[opt2]]==l) opt2++;
            for(int tqi=opt1;tqi<opt2;tqi++) 
            {
                int qi=bi[tqi];
                int r=rq[qi];
                if(n>g*r) 
                {
                    lans[qi]=-1;
                    continue;
                }
                if(rem==0) 
                {
                    lans[qi]=pref[g];
                    continue;
                }
                if(r==l)
                {
                    lans[qi]=-1;
                    continue; 
                }
                int rf=r-l;
                if(rem>g*rf) 
                {
                    lans[qi]=-1;
                    continue;
                }
                int rt=min(rf,rem); 
                int x=rem/rt;
                int y=rem%rt;
                int tmp=g-x-(bool)(y>0);
                int now=pref[tmp];
                int opt=tmp*l;
                if(y>0) 
                {
                    int sz=l+y;
                    int s=ssm(opt,opt+sz);
                    now=(now+((s*s)%MOD*invsq[sz])%MOD)%MOD;
                    opt+=sz;
                }
                if(x>0) 
                {
                    int sz=l+rt;
                    int invk=invsq[sz];
                    for(int k=0;k<x;k++) 
                    {
                        int s=ssm(opt,opt+sz);
                        now=(now+((s*s)%MOD*invk)%MOD)%MOD;
                        opt+=sz;
                    }
                }
                lans[qi]=now;
            }
            opt1=opt2;
        }
        for(auto tmp:lans) cout<<tmp<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    return Qaaxaap::work(),0;
} 