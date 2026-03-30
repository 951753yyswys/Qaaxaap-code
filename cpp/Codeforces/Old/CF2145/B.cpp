#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int l=0,r=0,m=0;
        for(int i=1;i<=k;i++)
        {
            char c;
            cin>>c;
            c-='0';
            if(c==0) l++;
            if(c==1) r++;
            if(c==2) m++;
        }
        if(k==n)
        {
            for(int i=1;i<=n;i++) cout<<'-';
            cout<<'\n';
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            // if(i<=l) cout<<'-';
            // else if(i<=l+m) cout<<'?';
            // else if(i>=n-r+1) cout<<'-';
            // else if(i>=n-l-m+1) cout<<'?';
            // else cout<<"+";
            if(l>=i||r>=n-i+1||m>=n-r-l)
                    cout << "-";
                else if(l+m<i&&r+m<n-i+1)
                    cout << "+";
                else
                    cout << "?";
        }
        cout<<'\n';
    }
    return 0;
}