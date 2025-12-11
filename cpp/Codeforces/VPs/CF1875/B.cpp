/*#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int sumn=0,summ=0;
        int maxn=0,maxm=0;
        int minn=1e10,minm=1e10;
        for(int i=1;i<=n;i++) 
        {
            int l;
            cin>>l;
            sumn+=l;
            maxn=max(maxn,l);
            minn=min(minn,l);
        }
        for(int i=1;i<=m;i++)
        {
            int l;
            cin>>l;
            summ+=l;
            maxm=max(maxm,l);
            minm=min(minm,l);
        }
        int ans=sumn;
        if(k==1) 
        {
            sumn=max(sumn,sumn-minn+maxm);
            cout<<sumn<<endl;
            continue;
        }
        if(k%2==0) 
        {
            // if(maxn>minm)
            // {
            //     sumn-=maxn;
            //     sumn+=minm;
            // }
            sumn-=minn,sumn+=maxm;
            maxm=max(maxm,minn);
            minm=min(minm,minn);
            summ-=minm,sumn+=maxn;
        }
        else 
        {
            if(maxm>minn) sumn-=minn,sumn+=maxm;
        }
        cout<<sumn<<endl;
    }
    return 0;
}*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    if (k >= 1) {
        auto min_a = min_element(a.begin(), a.end());
        auto max_b = max_element(b.begin(), b.end());
        if (*min_a < *max_b) {
            swap(*min_a, *max_b);
        }
    }
    if (k >= 2) {
        auto max_a = max_element(a.begin(), a.end());
        auto min_b = min_element(b.begin(), b.end());
        if (*min_b < *max_a) {
            swap(*max_a, *min_b);
        }
    }
    if (k > 2) {
        if (k % 2 == 1) {
            auto min_a = min_element(a.begin(), a.end());
            auto max_b = max_element(b.begin(), b.end());
            if (*min_a < *max_b) {
                swap(*min_a, *max_b);
            }
        }
    }
    ll sum = 0;
    for (ll x : a) sum += x;
    cout << sum << "\n";
}
int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);   
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}