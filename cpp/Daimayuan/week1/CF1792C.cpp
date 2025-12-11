#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> pos(n+1),inv(n+1);
		for(int i=1;i<=n;i++)
		{
			cin>>pos[i];
			inv[pos[i]]=i;
		}
		int ans=(int)ceil(n*0.5),l=ans,r=n-ans+1,mi=inv[l],mx=inv[r];
		if(mi>mx)
		{
			cout<<ans<<endl;
			continue;
		}
		while(l>1&&r<n&&inv[l-1]<mi&&inv[r+1]>mx) 
		{
			l--;
			r++;
			mx=inv[r];
			mi=inv[l];
			ans--;
		}
		cout<<ans-1<<endl;
	}
	return 0;
}

