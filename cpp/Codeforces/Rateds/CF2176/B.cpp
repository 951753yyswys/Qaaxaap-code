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
            int n,mxlen=0,len=0;
            cin>>n;
            vector<char> a(n*2);
            for(int i=0;i<n;i++) cin>>a[i],a[i+n]=a[i];
            for(auto tmp:a)
            {
                if(tmp=='1') mxlen=max(mxlen,len),len=0;
                else len++;
            }
            mxlen=max(mxlen,len);
            cout<<mxlen<<endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    return Qaaxaap::work(),0;
} 