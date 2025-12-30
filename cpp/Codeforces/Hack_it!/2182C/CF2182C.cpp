#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	void work()
	{
		cout<<"1\n5000\n";
		for(int j=1;j<=3;j++)
		{
			for(int i=5000;i>=1;i--)
			{
				cout<<(3-j)*5000+i<<' ';
			}
			cout<<endl;
		}		
	}
}
signed main()
{
	freopen("fh.in","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

