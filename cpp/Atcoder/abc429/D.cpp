#include<bits/stdc++.h>
using namespace std;
#define int long long
struct multiset_by_lkn
{
    long long cnt=0,root=0;
    struct tree{long long num,l,r,pri,siz;};
    vector<tree> t;
    multiset_by_lkn(){for(int i=1;i<=5;i++) t.push_back({0,0,0,0});}
    inline long long init(long long num){t.push_back({0,0,0,0}),t[++cnt]={num,0,0,rand(),1};return cnt;}
    inline void pushup(long long ro){t[ro].siz=t[t[ro].l].siz+t[t[ro].r].siz+1;}
    long long merge(long long lt,long long rt)
    {
        if(lt==0||rt==0) return max(lt,rt);
        if(t[lt].pri<t[rt].pri){t[lt].r=merge(t[lt].r,rt);pushup(t[lt].r);return lt;}
        else{t[rt].l=merge(lt,t[rt].l);pushup(t[rt].l);return rt;}
    }
    void split_val(long long ro,long long k,long long &lt,long long &rt)
    {
        if(!ro) return void(lt=rt=0);
        if(t[ro].num<=k){lt=ro;split_val(t[ro].r,k,t[ro].r,rt);}
        else{rt=ro;split_val(t[ro].l,k,lt,t[ro].l);}
        pushup(ro);
    }
    void split_rnk(long long ro,long long k,long long &lt,long long &rt)
    {
        if(!ro) return void(lt=rt=0);
        if(t[t[ro].l].siz<k){lt=ro;split_rnk(t[ro].r,k-t[t[ro].l].siz-1,t[ro].r,rt);}
        else{rt=ro;split_rnk(t[ro].l,k,lt,t[ro].l);}
        pushup(ro);
    }
    void add(long long x)
    {
        long long ro=init(x),lt,rt;
        split_val(root,x,lt,rt);
        root=merge(merge(lt,ro),rt);
    }
    long long query_val_front(long long v)
    {
        long long lt,rt;split_val(root,v-1,lt,rt);
        long long lr=lt,qm=-0x7fffffff;
        while(lr!=0) qm=max(qm,t[lr].num),lr=t[lr].r;
        root=merge(lt,rt);
        return qm;
    }
    long long query_val_back(long long v)
    {
        long long lt,rt;split_val(root,v,lt,rt);
        long long lr=rt,qm=0x7fffffff;
        while(lr!=0) qm=min(qm,t[lr].num),lr=t[lr].l;
        root=merge(lt,rt);
        return qm;
    }
    void delt(long long x)
    {
        long long lt,rt,mlt,mrt;
        split_val(root,x-1,lt,rt);
        split_rnk(rt,1,mlt,mrt);
        root=merge(lt,mrt);
    }
    long long query_rnk_to_val(long long rk)
    {
        long long lt,rt;split_rnk(root,rk,lt,rt);
        long long num=0,ro=lt;
        while(ro!=0) num=t[ro].num,ro=t[ro].r;
        root=merge(lt,rt);
        return num;
    }
    long long query_val_to_rnk(long long val)
    {
        long long lt,rt;split_val(root,val-1,lt,rt);
        long long num=t[lt].siz+1;
        root=merge(lt,rt);
        return num;
    }
    void insert(long long num){add(num);}
    long long count(long long num)
    {
        long long cnt1,cnt2;
        cnt1=query_val_to_rnk(num+1);
        cnt2=query_val_to_rnk(num);
        return cnt1-cnt2;
    }
    long long upper_bound(long long num)
    {
        int yk=num;
        while(yk==num) num=query_val_back(num);
        return num;
    }
    long long lower_bound(long long num)
    {
        int yk=num;
        while(yk==num) num=query_val_front(num);
        return num;
    }
    long long size(){return t[root].siz;}
} tril;
int d[2010101],siz[2010101],sum[2010101];
signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0),cout.tie(0);
    int n,m,c;
    cin>>n>>m>>c;
    for(int i=1;i<=n;i++) 
    {
        int l;
        cin>>l;
        tril.insert(l);
    }
    int lst=tril.query_rnk_to_val(1),cnt=0,lcnt=0;
    while(cnt<n)
    {
        //cout<<n<<' ';
        lcnt++;
        d[lcnt]=lst;
        siz[lcnt]=tril.count(lst);
        cnt+=siz[lcnt];
        lst=tril.upper_bound(lst);
    }
    for(int i=1;i<=lcnt;i++) 
    {
        siz[i+lcnt]=siz[i];
    }
    d[0]=-(m-d[lcnt]);
    int ans=0;
    for(int i=1;i<=lcnt*2;i++) sum[i]=sum[i-1]+siz[i];
    // for(int i=1;i<=lcnt*2;i++) cout<<sum[i]<<' ';
    // cout<<endl;
    // for(int i=0;i<=lcnt;i++) cout<<d[i]<<' ';
    // cout<<endl;
    for(int i=1;i<=lcnt;i++)
    {
        int pl=*lower_bound(sum+1,sum+lcnt*2+1,c+sum[i-1]);
        pl-=sum[i-1];
        //cout<<pl<<endl;
        ans+=pl*(d[i]-d[i-1]);
    }
    cout<<ans;
    return 0;
} 