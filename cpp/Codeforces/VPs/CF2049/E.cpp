#include<bits/stdc++.h>
using namespace std;
#define int long long
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
        int ansl,ansr;
        cout<<"? 1 "<<n/4<<endl<<flush;
        cin>>ansl;
        cout<<"? "<<n/4+1<<' '<<n/2<<endl<<flush;
        cin>>ansr;
        int ll;
        if(ansl==ansr)
            cout<<"? 1 "<<n/2<<endl<<flush;
        else 
            cout<<"? "<<n/2+1<<' '<<n<<endl<<flush;
        cin>>ll;
        if(ll)
        {
            if(ansl!=ansr)
            {
                int ls=0;
                for(int j=n/2;j>=1;j/=2) 
                {
                    cout<<"? "<<n-ls-j+1<<' '<<n<<endl<<flush;
                    int lll;
                    cin>>lll;
                    if(lll==0) ls+=j;
                }
                cout<<"! "<<ls+1<<endl<<flush;
            }
            else
            {
                int ls=0;
                for(int j=n/2;j>=1;j/=2) 
                {
                    cout<<"? 1 "<<j+ls<<endl<<flush;
                    int lll;
                    cin>>lll;
                    if(lll==0) ls+=j;
                }
                cout<<"! "<<ls+1<<endl<<flush;
            }
        }
        else
        {
            if(ansl!=ansr)
            {
                int ls=0;
                for(int j=n/2;j>=1;j/=2) 
                {
                    cout<<"? 1 "<<j+ls+n/2<<endl<<flush;
                    int lll;
                    cin>>lll;
                    if(lll==1) ls+=j;
                }
                cout<<"! "<<ls+n/2+1<<endl<<flush;
            }
            else
            {
                int ls=0;
                for(int j=n/2;j>=1;j/=2) 
                {
                    cout<<"? "<<n/2-j-ls+1<<' '<<n<<endl<<flush;
                    int lll;
                    cin>>lll;
                    if(lll==1) ls+=j;
                }
                cout<<"! "<<ls+n/2+1<<endl<<flush;
            }
        }
        //vector<int>
    }
    return 0;
} 