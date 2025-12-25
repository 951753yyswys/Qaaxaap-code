#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	void work()
	{
        int t;
        cin>>t;
        while(t--) 
        {
            int n,x,y,sump=0;
            cin>>n>>x>>y;
            string s;
            cin>>s;
            vector<int> p(n);
            for(auto &tmp:p) cin>>tmp,sump+=tmp;
            if(sump>x+y) 
            {
                cout<<"NO"<<endl;
                continue;
            }
            int r=x+y-sump,ymia=0,sum0=0,sb=0,ba=0,cnt0=0,cnt1=0,ev0=0,ev1=0;
            for(int i=0;i<n;i++) 
            {
                if(s[i]=='0') 
                {
                    cnt0++;
                    sum0+=p[i];
                    ymia+=p[i]/2+1;
                    if(p[i]%2==0) ev0++;
                } 
                else 
                {
                    cnt1++;
                    int v=(p[i]-1)/2;
                    sb+=v;
                    ba+=v;
                    if(p[i]%2==0) ev1++;
                }
            }
            int mia,mxa;
            if(cnt1>0) mia=ymia;
            else 
            {
                if(r<=ev0) mia=ymia;
                else mia=ymia+(r-ev0+1)/2; 
            }
	        if(cnt0>0) mxa=sum0+r+sb;
		    else 
            {
	            int tmp;
				if(r<=ev1) tmp=r;
	            else tmp=ev1+(r-ev1)/2;
				mxa=ba+tmp;
			}
            if(mia<=x&&x<=mxa) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}