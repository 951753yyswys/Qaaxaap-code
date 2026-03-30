#include<bits/stdc++.h>
using namespace std;
#define int long long
int yys[27]={114,514,514,191,191,810,810,1,1,114,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,114,2};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,cnt=114514;
        cin>>n;
        vector<int> ans(n);
        if(n%2==1) 
        {
            if(n<27)
            {
                cout<<-1<<endl;
                continue;
            }
            else
            {
                for(int i=0;i<27;i++) ans[i]=yys[i];
                for(int i=27;i<n;i+=2)
                {
                    ans[i]=ans[i+1]=cnt;
                    cnt++;
                }
            }
        }
        else
        {
            for(int i=0;i<n;i+=2)
            {
                ans[i]=ans[i+1]=cnt;
                cnt++;
            }
        }
        for(auto tmp:ans) cout<<tmp<<' ';
        cout<<endl;
    }
    return 0;
} 