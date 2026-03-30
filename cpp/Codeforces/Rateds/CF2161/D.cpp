#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = -1e15;
class SegmentTree 
{
private:
    int n;
    vector<int> tree;   
    void update(int pl,int val,int ro,int lt,int rt) 
    {
        if(lt==rt) 
        {
            if (val>tree[ro])
                tree[ro]=val;
            return;
        }
        int mid=lt+rt>>1;
        if(pl<=mid)
            update(pl,val,2*ro,lt,mid);
        else
            update(pl,val,2*ro+1,mid+1,rt);
        tree[ro]=max(tree[2*ro],tree[2*ro+1]);
    }
    int query(int l,int r,int ro,int lt,int rt) 
    {
        if(l>r) return INF;
        if(l<=lt&&rt<=r)
            return tree[ro];
        int mid=lt+rt>>1;
        int res=INF;
        if (l <= mid) 
            res = max(res, query(l, r, 2 * ro, lt, mid));
        if (r > mid) 
            res = max(res, query(l, r, 2 * ro + 1, mid + 1, rt));
        return res;
    }

public:
    SegmentTree(int size) 
    {
        n = size;
        tree.resize(4 * n, 0);
    }
    void update(int pl, int val) 
    {
        update(pl, val, 1, 1, n);
    }
    int query(int l, int r) 
    {
        return query(l, r, 1, 1, n);
    }
};
signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(auto &tmp:a) cin>>tmp;
        SegmentTree seg(n);
        for(int i=0;i<n;i++) 
        {
            int x = a[i];
            int tmp;
            if(x-1>=1) 
            {
                int lt_max=seg.query(1,x-2);
                int rt_max=seg.query(x,n);
                tmp=1+max(lt_max,rt_max);
            } 
            else
                tmp=1+seg.query(1,n);
            seg.update(x,tmp);
        }
        int mlen=seg.query(1,n);
        cout<<n-mlen<<endl;
    }
    return 0;
}