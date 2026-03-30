#include<bits/stdc++.h>
using namespace std;
int a[501010];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) 
        {
            char lll;
            cin>>lll;
            a[i]=lll-'0';
        }
        int ans=2*n;
        for(int tril=1;tril>=0;tril--)
        {
            int lx=0,mxr=0,st=1,lst=1;
            for(int i=1;i<=n;i++)
            {
                if(a[i]==1) lx++;
                else lx=0,lst=i+1;
                if(lx>mxr) mxr=lx,st=lst;//cout<<i<<endl;
            }
            int sum=0;
            for(int i=1;i<st;i++) sum+=a[i]+1;
            for(int i=st+mxr;i<=n;i++) sum+=a[i]+1;
            ans=min(ans,sum);
            if(tril) for(int i=1;i<=n;i++) a[i]=1-a[i];
            //cout<<"mxr:"<<mxr<<endl;
            //cout<<"lst:"<<lst<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}