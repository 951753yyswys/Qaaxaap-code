#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> pri;
int not_pri[221010];
void pre(int x)
{
    for(int i=2;i<=x;i++)
    {
        if(!not_pri[i]) pri.push_back(i);
        for(auto pri_j:pri)
        {
            if(pri_j*i>x) break;
            not_pri[pri_j*i]=1;
            if(i%pri_j==0) break;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    pre(200000);
    while(t--)
    {
        int n;
        cin>>n;
        unique_ptr<int[]> a=make_unique<int[]>(n),c=make_unique<int[]>(n);
        for(int i=0;i<n;i++) cin>>a[i],c[i]=0;
        
    }
    return 0;
} 