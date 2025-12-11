#include<bits/stdc++.h>
using namespace std;
int a[101010];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int x,k;
    cin>>k>>x;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==x) cnt++;
        if(cnt==k)
        {
            cout<<i;
            return 0;
        }
    }
    cout<<"Error";
    return 0;
}