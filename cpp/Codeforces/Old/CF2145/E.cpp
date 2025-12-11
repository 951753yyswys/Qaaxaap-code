#include <bits/stdc++.h>
using namespace std;
const int MAXN=500005;
const int MAXV=2000005;

int ac,dr,n,m;
int a[MAXN],d[MAXN];
int e[MAXN];
int fenw[MAXV];

inline void upd(int idx,int delta) {
    for(; idx<MAXV; idx|=idx+1)
        fenw[idx]+=delta;
}

inline int qur(int idx) {
    int res=0;
    for(; idx>=0; idx=(idx&(idx+1))-1)
        res+=fenw[idx];
    return res;
}
inline bool check(int p) {
    int total=0;
    int last_val=-1;
    //cout<<"P:"<<p<<endl;
    for(int val=0;val<MAXV&&total<p;)
    {
        int qval=qur(val);
        int count=qval-(last_val>=0 ? qur(last_val) : 0);

        if(count>0)
        {
            if(val<=total)
            {
                total+=count;
                //p = total;
            }
            else
                return false;
        }
        
        int left=val+1,right=MAXV-1;
        int next_val=MAXV;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(qur(mid)>qval)
            {
                next_val=mid;
                right=mid-1;
            }
            else
                left=mid+1;
        }

        if(next_val==MAXV)
            break;
        last_val=val;
        val=next_val;
    }
    //cout<<"p:"<<p<<" true!!!\n";
    return true;
}
inline int ser() 
{
    
    int left=0,right=n;
    int ans=0;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(check(mid))
        {
            ans=mid;
            left=mid+1;
        }
        else
            right=mid-1;
    }
    return ans;
}
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>ac>>dr>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>d[i];
    for(int i=0;i<n;i++)
    {
        e[i]=max(a[i]-ac,0)+max(d[i]-dr,0);
        upd(e[i],1);
    }
    cin>>m;
    for(int i=0; i<m; i++)
    {
        int k,na,nd;
        cin>>k>>na>>nd;
        k--;

        upd(e[k],-1);
        e[k]=max(na-ac,0)+max(nd-dr,0);
        upd(e[k],1);
        //cout<<"e_k"<<e[k]<<endl;
        //cout<<"qu:"<<qur(e[k])<<endl;
        cout<<ser()<<"\n";
    }

    return 0;
}