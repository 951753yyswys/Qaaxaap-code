#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace luuia {const int __SIZE=(1<<21)+1;
char ibuf[__SIZE],*iS,*iT,obuf[__SIZE],*oS=obuf,*oT=oS+__SIZE-1,_c,qu[55];int __f,qr,_eof;
#define Gc()(iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,__SIZE,stdin),(iS==iT?EOF:*iS++)):*iS++)
inline void flush(){fwrite(obuf,1,oS-obuf,stdout),oS=obuf;}inline void gc(char &x){x=Gc();}
inline void pc(char x){*oS++=x;if(oS==oT)flush();}
inline void pstr(const char *s){int __len=strlen(s);for(__f = 0;__f< __len;++__f)pc(s[__f]);}
inline void gstr(char *s){for(_c=Gc();_c<32||_c>126||_c==' ';)_c=Gc();
for(;_c>31&&_c<127&&_c!=' '&&_c!='\n'&&_c!='\r';++s,_c=Gc())*s=_c;*s=0;}
template<class I>inline bool read(I &x){_eof=0;
for(__f=1,_c=Gc();(_c<'0'||_c>'9')&&!_eof;_c=Gc()){if(_c=='-')__f=-1;_eof|=_c==EOF;}
for(x=0;_c<='9'&&_c>='0'&&!_eof;_c=Gc())x=x*10+(_c&15),_eof|=_c==EOF;x*=__f;return !_eof;}
template<class I>inline void print(I x){if(!x)pc('0');if(x<0)pc('-'),x=-x;
while(x)qu[++qr]=x%10+'0',x/= 10;while(qr)pc(qu[qr--]);}struct Flusher_{~Flusher_(){flush();}}io_flusher_;
}using luuia::pc;using luuia::gc;using luuia::pstr;using luuia::gstr;using luuia::read;using luuia::print;
struct segs
{
    int l,r,id,flag;
};
bool cmp(segs x,segs y)
{
    if(x.l!=y.l) return x.l<y.l;
    return x.r>y.r;
}
bool cmp1(segs x,segs y)
{
    if(x.r!=y.r) return x.r>y.r;
    return x.l<y.l;
}
signed main()
{
    int t;
    read(t);
    while(t--)
    {
        int n;
        read(n);
        vector<segs> seg(n);
        vector<int> ans(n);
        for(int i=0;i<n;i++) read(seg[i].l),read(seg[i].r),seg[i].id=i,seg[i].flag=1;
        sort(seg.begin(),seg.end(),cmp);
        for(int i=1;i<n;i++)
            if(seg[i].l==seg[i-1].l&&seg[i].r==seg[i-1].r) seg[i].flag=seg[i-1].flag=0;
        set<int> s;
        for(int i=0;i<n;i++)
        {
            if(s.empty())
            {
                s.insert(seg[i].r);
                continue;
            }
            auto it=s.lower_bound(seg[i].r);
            if(it==s.end()) 
            {
                s.insert(seg[i].r);
                continue;
            }
            if(seg[i].flag) ans[seg[i].id]+=(*it-seg[i].r);
            s.insert(seg[i].r);
        }
        for(int i=0;i<n;i++) swap(seg[i].l,seg[i].r),seg[i].l*=-1,seg[i].r*=-1;
        sort(seg.begin(),seg.end(),cmp);
        s.clear();
        for(int i=0;i<n;i++)
        {
            if(s.empty())
            {
                s.insert(seg[i].r);
                continue;
            }
            auto it=s.lower_bound(seg[i].r);
            if(it==s.end()) 
            {
                s.insert(seg[i].r);
                continue;
            }
            if(seg[i].flag) ans[seg[i].id]+=(*it-seg[i].r);
            s.insert(seg[i].r);
        }
        for(auto tmp:ans) print(tmp),pc('\n');
    }
    return 0;
} 