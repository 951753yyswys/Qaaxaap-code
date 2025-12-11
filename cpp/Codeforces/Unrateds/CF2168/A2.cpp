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
            stack<int> st;
            for(int j=1;j<=10;j++)
            {
                st.push(tmp%26);
                tmp/=26;
            }
            for(int j=1;j<=10;j++)
            {
                cout<<char('a'+st.top());
                st.pop();
            }
        }     
    }
    else 
    {
        string s;
        cin>>s;
        cout<<s.size()/10<<endl;
        int cnt=-1;
        for(int i=0;i<s.size()/10;i++)
        {
            int tmp=0;
            for(int j=1;j<=10;j++)
            {
                cnt++;
                tmp*=26;
                tmp+=s[cnt]-'a';
            }
            cout<<tmp<<' ';
        }
    }
    return 0;
} 