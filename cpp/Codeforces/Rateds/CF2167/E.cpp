#include<bits/stdc++.h>
#define int long long
using namespace std;
bool check(int d,vector<int>& a,int x,int k) 
{
    int n=a.size();
    if(d==0) return true;
    vector<pair<int,int>> tmp;
    for(int i=0;i<n;i++) 
    {
        int lt=a[i]-d+1;
        int rt=a[i]+d-1;
        if(lt>x||rt<0) 
            continue;
        lt=max(0ll,lt);
        rt=min(x,rt);
        if(lt<=rt) 
            tmp.push_back({lt,rt});
    }
    if(tmp.empty()) 
        return 1;
    sort(tmp.begin(),tmp.end());
    vector<pair<int,int>> md;
    int st=tmp[0].first,en=tmp[0].second;
    for(int i=1;i<tmp.size();i++) 
        if(tmp[i].first<=en+1) 
            en=max(en,tmp[i].second);
        else 
        {
            md.push_back({st,en});
            st=tmp[i].first;
            en=tmp[i].second;
        }
    md.push_back({st,en});
    int sb=0;
    for(auto& seg:md)
        sb+=seg.second-seg.first+1;
    return x+1-sb>=k;
}
signed main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) 
    {
        int n,k,x;
        cin>>n>>k>>x;
        vector<int> a(n);
        for(auto &tmp:a) cin>>tmp;
        sort(a.begin(),a.end());
        int ll=0,rr=x+1;
        while(ll<rr) 
        {
            int mid=ll+rr+1>>1;
            if(check(mid,a,x,k))
                ll=mid;
            else 
                rr=mid-1;
        }
        int dt=ll;
        if(dt==0) 
        {
            for(int i=0;i<k;i++)
                cout<<i<<' ';
            cout<<endl;
        } 
        else 
        {
            vector<pair<int,int>> tmp;
            for(int i=0;i<n;i++) 
            {
                int lt=a[i]-dt+1;
                int rt=a[i]+dt-1;
                if(lt>x||rt<0) 
                    continue;
                lt=max(0ll,lt);
                rt=min(x,rt);
                if(lt<=rt) 
                    tmp.push_back({lt,rt});
            }
            vector<pair<int,int>> md;
            if(!tmp.empty()) 
            {
                sort(tmp.begin(),tmp.end());
                int st=tmp[0].first,en=tmp[0].second;
                for(int i=1;i<tmp.size();i++) 
                    if(tmp[i].first<=en+1) 
                        en=max(en,tmp[i].second);
                    else 
                    {
                        md.push_back({st,en});
                        st=tmp[i].first;
                        en=tmp[i].second;
                    }
                md.push_back({st,en});
            }
            vector<int> ans;
            int now=0;
            for(auto& seg:md) 
            {
                int l=seg.first,r=seg.second;
                if(now<l) 
                {
                    for(int i=now;i<l;i++) 
                    {
                        ans.push_back(i);
                        if(ans.size()==k) 
                            break;
                    }
                }
                if(ans.size()==k) 
                    break;
                now=r+1;
            }
            if(ans.size()<k&&now<=x) 
                for(int i=now;i<=x;i++) 
                {
                    ans.push_back(i);
                    if(ans.size()==k) 
                        break;
                }
            for(int i=0;i<k;i++) 
                cout<<ans[i]<<' ';
            cout<<endl;
        }
    }
    return 0;
}