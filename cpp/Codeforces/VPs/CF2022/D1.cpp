#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;      
        int emp1=-1,emp2=-1;
        for(int i=1;i<n;i+=2)
        {
            int ans1,ans2;
            cout<<"? "<<i<<' '<<i+1<<endl;
            cin>>ans1;
            cout<<"? "<<i+1<<' '<<i<<endl;
            cin>>ans2;
            if(ans1==ans2) continue;
            emp1=i;
            emp2=i+1;
        }
        if(emp1==-1) 
        {
            cout<<"! "<<n<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            if(i==emp1) continue;
            if(i==emp2) continue;
            cout<<"? "<<i<<' '<<emp1<<endl;
            int ans1,ans2;
            cin>>ans1;
            cout<<"? "<<emp1<<' '<<i<<endl;
            cin>>ans2;
            if(ans1==ans2) cout<<"! "<<emp2<<endl;
            else cout<<"! "<<emp1<<endl;
            break;
        }
    }
    return 0;
} 