#include <bits/stdc++.h>
#define int long long
#define sor(i,l,r) for(int i=l;i<=r;++i)
#define ros(i,r,l) for(int i=r;i>=l;--i)
using namespace std;
namespace IO
{
    const int __SIZE = (1 << 21) + 1;
    char ibuf[__SIZE], *iS, *iT, obuf[__SIZE], *oS = obuf, *oT = oS + __SIZE - 1, _c, qu[55];
    int __f, qr, _eof;
#define Gc() (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++)

    inline void flush()
    {
        fwrite(obuf, 1, oS - obuf, stdout);
        oS = obuf;
    }

    inline void gc(char &x)
    {
        x = Gc();
    }

    inline void pc(char x)
    {
        *oS++ = x;
        if (oS == oT)
        {
            flush();
        }
    }

    inline void pstr(const char *s)
    {
        int __len = strlen(s);
        for (__f = 0; __f < __len; ++__f)
        {
            pc(s[__f]);
        }
    }

    inline void gstr(char *s)
    {
        for (_c = Gc(); _c < 32 || _c > 126 || _c == ' ';)
        {
            _c = Gc();
        }
        for (; _c > 31 && _c < 127 && _c != ' ' && _c != '\n' && _c != '\r'; ++s, _c = Gc())
        {
            *s = _c;
        }
        *s = 0;
    }

    template <class I>
    inline bool read(I &x)
    {
        _eof = 0;
        for (__f = 1, _c = Gc(); (_c < '0' || _c > '9') && !_eof; _c = Gc())
        {
            if (_c == '-')
            {
                __f = -1;
            }
            _eof |= _c == EOF;
        }
        for (x = 0; _c <= '9' && _c >= '0' && !_eof; _c = Gc())
        {
            x = x * 10 + (_c & 15), _eof |= _c == EOF;
        }
        x *= __f;
        return !_eof;
    }

    template <class I>
    inline void print(I x)
    {
        if (!x)
        {
            pc('0');
        }
        if (x < 0)
        {
            pc('-');
            x = -x;
        }
        while (x)
        {
            qu[++qr] = x % 10 + '0', x /= 10;
        }
        while (qr)
        {
            pc(qu[qr--]);
        }
    }

    struct Flusher_
    {
        ~Flusher_() { flush(); }
    } io_flusher_;
}
using IO::gc;
using IO::gstr;
using IO::pc;
using IO::print;
using IO::pstr;
using IO::read;
namespace Revitalize
{
    constexpr const int N = 5e5 + 5, P = 998244353;
    int T,n,a[N],s[N],t[N];
    unordered_map<int,int> has;
    vector<int> p[N];
    mt19937 rnd(time(0));
    inline void work(){int cl=clock();
        read(n);
        sor(i,1,n){read(a[i]);if(!has.count(a[i])) has[a[i]]=rnd();}
        if(!has.count(0)){cout<<n*(n+1)/2;return ;}
        t[0]=has[0];
        sor(i,1,n-1){
            if(!has.count(i)) has[i]=rnd();
            t[i]=t[i-1]+has[i];
        }
        sor(i,1,n) s[i]=s[i-1]+has[a[i]];
        sor(i,1,n) if(a[i]<n) p[a[i]].push_back(i);
        int ans=0;
        sor(i,0,n-1){
            if(!p[i].size()) continue;
            int lim=1;
            for(int j:p[i]){
                for(int l=max(lim,j-i),r=l+i;l<=j&&r<=n;l++,r++){
                    if(s[r]-s[l-1]==t[i]) ans++;
                }
                lim=j;
            }
        }
        cout<<ans;
        //cout<<clock()-cl;
    }
}
signed main()
{
    freopen("ex_mex3.in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return Revitalize::work(), 0;
}