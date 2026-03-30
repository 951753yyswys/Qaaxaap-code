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
        int ans=0,ls=0;
        queue<pair<int,int>> q,q0,q1;
        for(int i=1;i<n;i++) q.push({i,0});
        for(int i=0;i<=__lg(n);i++)
        {
            int siz=1+q.size();
            if(siz==1) 
            {
                ans+=ls<<i;
                continue;
            }
            //cout<<"mi:"<<i<<endl;
            int cnt1=0,cnt0=0;
            while(!q.empty())
            {
                auto f=q.front();
                q.pop();
                cout<<"? "<<f.first<<' '<<(1<<i)<<endl<<flush;
                int qa;
                cin>>qa;
                if(qa==1) cnt1++,q1.push(f);
                else cnt0++,q0.push(f);
            }
            bool flag=0;
            if(siz%2==0)
            {
                if(cnt0>cnt1) flag=1;
                else flag=0;
            }
            else
            {
                if(cnt1>cnt0) flag=0;
                else flag=1;
            }
            ans+=flag<<i;
            //cout<<"mu:"<<flag<<endl;
            if(flag==1)
            {
                while(!q1.empty()) 
                {
                    q.push(q1.front());
                    q1.pop();
                }
                ls=0;
            }
            else
            {
                while(!q0.empty())
                {
                    q.push(q0.front());
                    q0.pop();
                }
                ls=1;
            }
        }
        cout<<"! "<<ans<<endl<<flush;
    }
    return 0;
} 