#include<bits/stdc++.h>
using namespace std;
struct treap
{
    long long cnt=0,root=0;
    struct tree{long long num,l,r,pri,siz;};
    vector<tree> t;
    treap(){for(int i=1;i<=5;i++) t.push_back({0,0,0,0});}
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
} tril;
int main()//luogu p3369
{
    long long n;
    cin>>n;
    while(n--)
    {
        long long opt,x;
        cin>>opt>>x;
        if(opt==1) tril.add(x);
        if(opt==2) tril.delt(x);
        if(opt==3) cout<<tril.query_val_to_rnk(x)<<endl;
        if(opt==4) cout<<tril.query_rnk_to_val(x)<<endl;
        if(opt==5) cout<<tril.query_val_front(x)<<endl;
        if(opt==6) cout<<tril.query_val_back(x)<<endl;
    }
    return 0;
}