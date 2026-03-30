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
        int n,X;
        cin>>n>>X;
        vector<int> a(n);
        int sum=0;
        for(auto &tmp:a) 
        {
            cin>>tmp;
            sum+=tmp;
        }
        int L=sum/X;
        sort(a.begin(),a.end());
        vector<int> T,U;
        for(int i=n-1;i>=0;i--) 
        {
            if(T.size()<L)
                T.push_back(a[i]);
            else
                U.push_back(a[i]);
        }
        sort(T.rbegin(), T.rend());
        sort(U.begin(), U.end());
        vector<int> ord;
        int S=0;
        int ans=X;
        int i=0,j=0;
        while(i<T.size()||j<U.size()) 
        {
            if(i<T.size()&&(j>=U.size()||S>=ans-T[i])) 
            {
                ord.push_back(T[i]);
                S+=T[i];
                i++;
                ans+=X;
            } 
            else 
            {
                ord.push_back(U[j]);
                S+=U[j];
                j++;
            }
        }
        int lans=0;
        for(auto tmp:T) 
            lans+=tmp;
        cout<<lans<<endl;
        for(auto tmp:ord)
            cout<<tmp<<" ";
        cout<<endl;
    }
    return 0;
}