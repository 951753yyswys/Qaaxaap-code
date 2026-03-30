#include<bits/stdc++.h>
using namespace std;
char c[]={'A','B','C'};
int main()
{
    vector<pair<int,int>> a(3);
    for(int i=0;i<3;i++) cin>>a[i].first,a[i].second=i;
    sort(a.begin(),a.end());
    int d;
    cin>>d;
    if(a[0].first==a[1].first||a[1].first==a[2].first) cout<<"Report";
    else 
    {
        for(int i=0;i<3;i++)
        if(d==a[i].first)
        {
            cout<<c[a[i].second];
            return 0;
        }
        cout<<c[a[1].second];
    }
    return 0;
}