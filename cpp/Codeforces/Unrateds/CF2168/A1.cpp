#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string opt;
    cin>>opt;
    if(opt=="first")
    {
        int n;
        cin>>n;
        //unique_ptr<int[]> a=make_unique<int[]>(n);
        for(int i=0;i<n;i++) 
        {
            int tmp;
            cin>>tmp;
            cout<<char(tmp+'a'-1);
        }     
    }
    else 
    {
        string s;
        cin>>s;
        cout<<s.size()<<endl;
        for(int i=0;i<s.size();i++)
        {
            cout<<(int)((int)s[i]-'a'+1)<<' ';
        }
    }
    return 0;
} 