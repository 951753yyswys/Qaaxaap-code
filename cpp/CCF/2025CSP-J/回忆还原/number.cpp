#include<bits/stdc++.h>
using namespace std;
#define int long long
int cnt[114];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string s;
    cin>>s;
    for(char tmp:s)
    {
        if(tmp<='9'&&tmp>='0') cnt[tmp-'0']++;
    }
    for(int i=9;i>=0;i--)
    {
        while(cnt[i]) 
        {
            cout<<i;
            cnt[i]--;
        }
    }
    return 0;
} 