#include<bits/stdc++.h>
using namespace std;
namespace IO 
{
    const int __SIZE=(1<<21)+1;
    char ibuf[__SIZE],*iS,*iT,obuf[__SIZE],*oS=obuf,*oT=oS+__SIZE-1,_c,qu[55];int __f,qr,_eof;
    #define Gc()(iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,__SIZE,stdin),(iS==iT?EOF:*iS++)):*iS++)
    inline void flush(){fwrite(obuf,1,oS-obuf,stdout),oS=obuf;}
    inline void gc(char &x){x=Gc();}
    inline void pc(char x)
    {
        *oS++=x;
        if(oS==oT)flush();
    }
    inline void pstr(const char *s)
    {
        int __len=strlen(s);
        for(__f = 0;__f< __len;++__f) pc(s[__f]);
    }
    inline void gstr(char *s)
    {
        for(_c=Gc();_c<32||_c>126||_c==' ';) _c=Gc();
        for(;_c>31&&_c<127&&_c!=' '&&_c!='\n'&&_c!='\r';++s,_c=Gc()) *s=_c;*s=0;
    }
    template<class I> 
    inline bool read(I &x)
    {   
        _eof=0;
        for(__f=1,_c=Gc();(_c<'0'||_c>'9')&&!_eof;_c=Gc())
        {
            if(_c=='-')__f=-1;
            _eof|=_c==EOF;
        }
        for(x=0;_c<='9'&&_c>='0'&&!_eof;_c=Gc()) 
            x=x*10+(_c&15),_eof|=_c==EOF;x*=__f;
        return !_eof;
    }
    template<class I>
    inline void print(I x)
    {
        if(!x)pc('0');if(x<0)pc('-'),x=-x;
        while(x)qu[++qr]=x%10+'0',x/= 10;
        while(qr)pc(qu[qr--]);
    }
    struct Flusher_
    {
        ~Flusher_(){flush();}
    } io_flusher_;
}
using IO::pc;using IO::gc;using IO::pstr;using IO::gstr;using IO::read;using IO::print;
namespace DS
{
    template<typename T>
    class AVL
    {
    private:
        struct tree
        {
            int l,r,fa,height,siz;
            T val;
            tree()=default;
            ~tree()=default;
        };
        int cnt,root;
        vector<tree> t;
        queue<int> rubbish;
        inline int get_height(int ro)
        {
            if(!ro) return 0;
            return t[ro].height;
        }
        inline int get_balance(int ro)
        {
            if(!ro) return 0;
            return get_height(t[ro].l)-get_height(t[ro].r);
        }
        inline void update_height(int ro)
        {
            if(!ro) return;
            t[ro].height=max(get_height(t[ro].l),get_height(t[ro].r))+1;
            t[0].siz=0;
            t[ro].siz=1+t[t[ro].l].siz+t[t[ro].r].siz;
        }
        inline void left_rotate(int ro)
        {
            int fa=t[ro].fa;
            int rson=t[ro].r;
            int rlson=t[rson].l;
            t[rson].l=ro;
            t[ro].fa=rson;
            t[ro].r=rlson;
            if(rlson) t[rlson].fa=ro;
            t[rson].fa=fa;
            if(fa)
            {
                if(t[fa].l==ro) t[fa].l=rson;
                else t[fa].r=rson;
            }
            else root=rson;
            update_height(ro);
            update_height(rson);
        }
        inline void right_rotate(int ro)
        {
            int fa=t[ro].fa;
            int lson=t[ro].l;
            int lrson=t[lson].r;
            t[lson].r=ro;
            t[ro].fa=lson;
            t[ro].l=lrson;
            if(lrson) t[lrson].fa=ro;
            t[lson].fa=fa;
            if(fa)
            {
                if(t[fa].l==ro) t[fa].l=lson;
                else t[fa].r=lson;
            }
            else root=lson;
            update_height(ro);
            update_height(lson);
        }
        inline void balance(int ro)
        {
            while(ro)
            {
                update_height(ro);
                int balance_factor=get_balance(ro);
                if(balance_factor>1)
                {
                    if(get_balance(t[ro].l)<0) left_rotate(t[ro].l);
                    right_rotate(ro);
                }
                else if(balance_factor<-1)
                {
                    if(get_balance(t[ro].r)>0) right_rotate(t[ro].r);
                    left_rotate(ro);
                }
                ro=t[ro].fa;
            }
        }
        inline int new_node(T x)
        {
            int ro;
            if(rubbish.empty())
            {
                ro=++cnt;
                if(ro>=t.size()) t.push_back({0,0,0,0,T{}});
            }
            else
            {
                ro=rubbish.front();
                rubbish.pop();
            }
            t[ro].l=0;
            t[ro].r=0;
            t[ro].fa=0;
            t[ro].height=1;
            t[ro].val=x;
            t[ro].siz=1;
            return ro;
        }
        inline void add_private(T x)
        {
            if(!root)
            {
                root=new_node(x);
                return;
            }
            int now=root;
            int parent=0;
            while(now)
            {
                parent=now;
                if(x<t[now].val) now=t[now].l;
                else now=t[now].r;
            }
            int new_ro=new_node(x);
            t[new_ro].fa=parent;
            if(x<t[parent].val) t[parent].l=new_ro;
            else t[parent].r=new_ro;
            balance(parent);
        }
        inline int find_min(int ro)
        {
            while(t[ro].l) ro=t[ro].l;
            return ro;
        }
        inline void transplant(int u,int v)
        {
            if(!t[u].fa) root=v;
            else if(u==t[t[u].fa].l) t[t[u].fa].l=v;
            else t[t[u].fa].r=v;
            if(v) t[v].fa=t[u].fa;
        }
        inline void del_private(T x)
        {
            int now=root;
            while(now&&t[now].val!=x)
            {
                if(x<t[now].val) now=t[now].l;
                else now=t[now].r;
            }
            if(!now) return;
            int balance_start;
            if(!t[now].l) 
            {
                balance_start=t[now].fa;
                transplant(now,t[now].r);
            }
            else if(!t[now].r) 
            {
                balance_start=t[now].fa;
                transplant(now,t[now].l);
            }
            else 
            {
                int successor=find_min(t[now].r);
                balance_start=t[successor].fa;
                if(t[successor].fa!=now) 
                {
                    transplant(successor,t[successor].r);
                    t[successor].r=t[now].r;
                    t[t[successor].r].fa=successor;
                }
                transplant(now,successor);
                t[successor].l=t[now].l;
                t[t[successor].l].fa=successor;
                if(balance_start==now) balance_start=successor;
            }
            rubbish.push(now);
            balance(balance_start);
        }
        inline int query_value_to_rank(T x)
        {
            int ro=root;
            int rank=1;
            while(ro)
            {
                if(x<=t[ro].val) ro=t[ro].l;
                else 
                {
                    rank+=1;
                    if(t[ro].l) rank+=t[t[ro].l].siz;
                    ro=t[ro].r;
                }
            }
            return rank;
        }
        inline T query_rank_to_value(int rank)
        {
            int ro=root;
            while(ro)
            {
                int left_size=0;
                if(t[ro].l) left_size=t[t[ro].l].siz;
                if(rank<=left_size) ro=t[ro].l;
                else if(rank==left_size+1) return t[ro].val;
                else 
                {
                    rank-=left_size+1;
                    ro=t[ro].r;
                }
            }
            return T{};
        }
        inline T query_pre(T x)
        {
            int ro=root;
            T pre=T{};
            while(ro)
            {
                if(t[ro].val<x) 
                {
                    pre=t[ro].val;
                    ro=t[ro].r;
                }
                else ro=t[ro].l;
            }
            return pre;
        }
        inline T query_suc(T x)
        {
            int ro=root;
            T suc=T{};
            while(ro)
            {
                if(t[ro].val>x) 
                {
                    suc=t[ro].val;
                    ro=t[ro].l;
                }
                else ro=t[ro].r;
            }
            return suc;
        }
    public:
        AVL()
        {
            cnt=0;
            root=0;
            t.resize(10);
        }
        inline void add(T x){add_private(x);}
        inline void del(T x){del_private(x);}
        inline int qur(T x){return query_value_to_rank(x);}
        inline T quv(int x){return query_rank_to_value(x);}
        inline T pre(T x){return query_pre(x);}
        inline T suc(T x){return query_suc(x);}
    };
};
using namespace DS;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t; 
    AVL<int> dzd;
    read(t);
    while(t--)
    {
        int opt,x;
        read(opt),read(x);
        if(opt==1) dzd.add(x);
        if(opt==2) dzd.del(x);
        if(opt==3) print(dzd.qur(x)),pc('\n');
        if(opt==4) print(dzd.quv(x)),pc('\n');
        if(opt==5) print(dzd.pre(x)),pc('\n');
        if(opt==6) print(dzd.suc(x)),pc('\n');
    }
    return 0;
}