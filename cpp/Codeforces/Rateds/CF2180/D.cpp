#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    struct segs 
    {
        int cnt;
        int l,h; 
    };
    const int INF=(1ll<<60);
	void work()
	{
        int t;
        cin>>t;
        while (t--) 
        {
            int n;
            cin>>n;
            vector<int> x(n);
            for(auto &tmp:x) cin>>tmp;
            if(n==1) 
            {
                cout<<0<<endl;
                continue;
            }
            vector<segs> seg;
            seg.push_back({0,0,INF}); 
            for(int i=0;i<n-1;i++) 
            {
                int d=x[i+1]-x[i];
                vector<segs> wt;
                for(auto st:seg) 
                {
                    int l=max(0ll,st.l);
                    int h=st.h;
                    if(l>=h) continue;
                    int a=max(l,0ll);
                    int b=min(h,d);
                    if(a>=b) continue;
                    if(l<d) 
                    {
                        int h2=d-l; 
                        if(0<h2) wt.push_back({st.cnt,0,h2});
                    }
                    int l2=d-b;
                    int h2=d-a;
                    if(l2<0) l2=0;
                    if(l2<h2) wt.push_back({st.cnt+1,l2,h2});
                }
                vector<segs> kp;
                for(int p=0;p<wt.size();p++) 
                {
                    bool flag=0;
                    auto b=wt[p];
                    for(int q=0;q<wt.size();q++) if(p!=q) 
                    {
                        auto a=wt[q];
                        if(a.cnt<b.cnt) continue;
                        if(a.l<=b.l&&a.h>=b.h) 
                        {
                            if(a.cnt>b.cnt||a.l<b.l||a.h>b.h) 
                            {
                                flag=1;
                                break;
                            }
                        }
                    }
                    if (!flag) kp.push_back(b);
                }
                seg.swap(kp);
            }
            int ans=0;
            for(auto &st:seg) ans=max(ans,st.cnt);
            cout<<ans<<endl;
        }
        return;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}