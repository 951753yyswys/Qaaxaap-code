#include<bits/stdc++.h>
using namespace std;
int d[801010];
char s[801010];
int main()
{
    int q,en=0,ans=0,fail=0;
    cin>>q;
    stack<int> f;
    while(q--)
    {
        int opt;
        cin>>opt;
        if(opt==1)
        {
            char c;
            cin>>c;
            s[++en]=c;
            if(c=='(') f.push(en),ans=0;
            else 
            {
                if(!f.empty())
                {
                    d[en]=f.top();
                    f.pop();
                    if(f.empty()&&fail==0) ans=1;
                }
                else
                {
                    fail++;
                    d[en]=-1;
                    ans=0;
                }
            }
            if(ans) cout<<"Yes\n";
            else cout<<"No\n";
        }
        else
        {
            if(s[en]=='(') 
            {
                f.pop();
                if(f.empty()&&fail==0) ans=1;
            }
            else
            {
                ans=0;
                if(d[en]==-1) fail--;
                else f.push(d[en]);
                if(fail==0&&f.empty()) ans=1;
            }
            en--;
            if(ans) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
    return 0;
}