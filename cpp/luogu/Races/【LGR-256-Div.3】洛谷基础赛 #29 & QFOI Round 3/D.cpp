#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    bool odk;
    int clg(int x) 
    {
        if(x<=1) return 0;
        return __lg(x-1)+1; 
    }
    int dl(int i,int a){return clg((a/2+i+2)/(i+1));}
    int db(int x,int a) 
    {
        int ans=INT_MAX;
        int up=0;
        int now=x;
        while(now>=1) 
        {
            ans=min(ans,up+dl(now,a));
            now>>=1;
            up++;
        }
        return ans;
    }
    int dt(int u,int v) 
    {
        int d=0;
        while(u!=v) 
        {
            if(u>v) u>>=1;
            else v>>=1;
            d++;
        }
        return d;
    }
    bool cmp(int id,int fl)
    {
        if(odk) return 0;
        if(fl==0)
        {
            if(id&1) return 0;
            return 1;
        }
        else 
        {
            if(id&1) return 1;
            return 0;
        }
    }
	void work()
	{
        int k,q;
        cin>>k>>q;
        vector<int> a(k+1),w(k+1);
        for(int i=1;i<=k;i++) cin>>a[i];
        int miw=INT_MAX;
        for(int i=1;i<=k;i++) w[i]=dl(1,a[i]),miw=min(miw,w[i]);
        odk=(k%2==1);
        while(q--) 
        {
            int s,t,u,v;
            cin>>s>>u>>t>>v;
            int dur=__lg(u);
            int dvr=__lg(v);
            int dub=db(u,a[s]);
            int dvb=db(v,a[t]);
            int ans=(1ll<<60);
            for(int i=0;i<2;i++) 
            {
                int cu=dub;
                if(i==0) cu=dur;
                int ca=cmp(s,i);
                for(int b=0;b<2;b++)
                {
                    int cv=dvb;
                    if(b==0) cv=dvr;
                    int cb=cmp(t,b);
                    int tmp=miw;
                    if(odk||ca==cb) tmp=0;
                    ans=min(ans,cu+cv+tmp);
                }
            }
            if(s==t) ans=min(ans,dt(u,v));
            cout<<ans<<endl;
        }
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

