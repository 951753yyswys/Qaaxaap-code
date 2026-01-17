#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	void work0()//WA on #1
	{
		int t;
		cin>>t;
		while(t--)
		{
			int n;
			cin>>n;
			string s;
			cin>>s;
			vector<int> ot(n);
			stack<int> st;
			for(int i=0;i<n;i++)
			{
				char tmp=s[i];
				if(tmp=='(') st.push(i);
				else 
				{
					int tp=st.top();
					ot[tp]=i;
					ot[i]=tp;
					st.pop();
				}
			}
			int ans=LLONG_MIN;
			for(int i=0;i<n;i++)
			{
				if(s[i]=='(') continue;
				int j=ot[i];
				if(j==i-1) continue;
				ans=n-j-1;
				break;
			}
			if(ans<0) cout<<-1<<endl;
			else cout<<ans<<endl;
		}
	}
	void work()
	{
		int t;
		cin>>t;
		while(t--)
		{
			int n;
			cin>>n;
			string s;
			cin>>s;
			vector<int> prf(n),suf(n);
			prf[0]=suf[n-1]=0;
			//for(int i=1;i<n;i++) prf[i]=prf[i-1]+(s[i]=='(');
			for(int i=n-2;i>=0;i--) suf[i]=suf[i+1]+(s[i]=='(');
			bool flag=0;
			for(int i=0;i<n-2;i++) if(s[i]==')'&&s[i+1]=='('&&suf[i+2]>0) flag=1;
			if(flag) cout<<n-2<<endl;
			else cout<<-1<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

