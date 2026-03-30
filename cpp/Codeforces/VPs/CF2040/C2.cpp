#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> ans;
int n,k;
void dfs(int val,int len)
{
    if(!len) return;
    if(k<len/2) 
    {
        ans.push_back(val);
        k-=len/4;
        dfs(1,len/2);
    }
    else
    {
        k-=len/2;
        dfs(val+1,len/2);
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int l2=__lg(k);
        if(l2>=n) 
        {
            cout<<-1<<endl;
            continue;
        }
        ans.clear();
        dfs(1,1ll<<n);
        for(auto tmp:ans) cout<<tmp<<' ';
        cout<<endl;
    }
    return 0;
} 