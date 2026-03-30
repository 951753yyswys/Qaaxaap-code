#include<bits/stdc++.h>
using namespace std;
struct treap
{
    long long cnt=0,root=0;
    struct tree{long long num,l,r,pri,siz;} t[101010];
    inline long long init(long long num){t[++cnt]={num,0,0,rand(),1};return cnt;}
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
};
struct segment_tree
{
    long long mod;
    struct node{long long l,r,sum,lazy_and,lazy_times;} t[2000001];
    void build(long long ro,long long l,long long r)
    {
        t[ro]={l,r,0,0,1};
        if(l==r) return;
        long long mid=(l+r)/2;
        build(ro*2,l,mid);
        build(ro*2+1,mid+1,r);
        t[ro].sum=(t[ro*2].sum+t[ro*2+1].sum)%mod;
    }
    inline void init(long long siz,long long m){mod=m;build(1,1,siz);}
    inline void pushdown(long long ro)
    {
        long long ll=t[ro*2].r-t[ro*2].l+1;
        long long rl=t[ro*2+1].r-t[ro*2+1].l+1;
        t[ro*2].sum=(t[ro].lazy_times*t[ro*2].sum+t[ro].lazy_and*ll)%mod;
        t[ro*2+1].sum=(t[ro].lazy_times*t[ro*2+1].sum+t[ro].lazy_and*rl)%mod;
        t[ro*2].lazy_times=(t[ro].lazy_times*t[ro*2].lazy_times)%mod;
        t[ro*2+1].lazy_times=(t[ro].lazy_times*t[ro*2+1].lazy_times)%mod;
        t[ro*2].lazy_and=(t[ro*2].lazy_and*t[ro].lazy_times+t[ro].lazy_and)%mod;
        t[ro*2+1].lazy_and=(t[ro*2+1].lazy_and*t[ro].lazy_times+t[ro].lazy_and)%mod;
        t[ro].lazy_and=0;
        t[ro].lazy_times=1;
    }
    void update_times(long long ro,long long l,long long r,long long s)
    {
        if(t[ro].l>=l&&t[ro].r<=r)
        {
            t[ro].lazy_times=t[ro].lazy_times*s%mod;
            t[ro].sum=t[ro].sum*s%mod;
            t[ro].lazy_and=t[ro].lazy_and*s%mod;
            return;
        }
        pushdown(ro);
        if(t[ro*2].r>=l) update_times(ro*2,l,r,s);
        if(t[ro*2+1].l<=r) update_times(ro*2+1,l,r,s);
        t[ro].sum=(t[ro*2].sum+t[ro*2+1].sum)%mod;
    }
    void update_and(long long ro,long long l,long long r,long long s)
    {
        if(t[ro].l>=l&&t[ro].r<=r)
        {
            t[ro].lazy_and=(t[ro].lazy_and+s)%mod;
            t[ro].sum=(t[ro].sum+s*(t[ro].r-t[ro].l+1))%mod;
            return;
        }
        pushdown(ro);
        if(t[ro*2].r>=l) update_and(ro*2,l,r,s);
        if(t[ro*2+1].l<=r) update_and(ro*2+1,l,r,s);
        t[ro].sum=(t[ro*2].sum+t[ro*2+1].sum)%mod;
    }
    long long query(long long ro,long long l,long long r)
    {
        if(t[ro].l>=l&&t[ro].r<=r) return t[ro].sum;
        if(t[ro].r<l||t[ro].l>r) return 0;
        pushdown(ro);
        long long ans=0;
        if(t[ro*2].r>=l) ans=(ans+query(ro*2,l,r))%mod;
        if(t[ro*2+1].l<=r) ans=(ans+query(ro*2+1,l,r))%mod;
        return ans%mod;
    }
    inline void update_and(long long l,long long r,long long val){update_and(1,l,r,val);}
    inline void update_times(long long l,long long r,long long val){update_times(1,l,r,val);}
    inline long long query(long long l,long long r){return query(1,l,r);}
};
int main()
{
    return 0;
}