#include<bits/stdc++.h>
#define int long long
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
namespace Qaaxaap
{
	const int N=5e5+5,mod=998244353;
	int mp[4040][4040],dp[1010][5050],su[4040],a[4040];
	int sum(int j,int i)
	{
		if((i-j)&1) return su[i]+su[j-1]-2*su[(int)ceil(j+i-1>>1)];
		else return su[i]+su[j-1]-su[(int)ceil(j+i-1>>1)]-su[(int)ceil(j+i+1>>1)];
	}
	void dfs(int lt,int rt,int mi,int mx,int c)
	{
		if(lt>rt) return;
		int mid=lt+rt>>1,opt=mi;
		for(int i=mi;i<min(mx+1,mid);i++) 
		{
			if(dp[c][mid]>dp[c-1][i]+sum(i+1,mid))
			{
				opt=i;
				dp[c][mid]=dp[c-1][i]+sum(i+1,mid);
			}
		}
		dfs(lt,mid-1,mi,opt,c);
		dfs(mid+1,rt,opt,mx,c);
	}
	void work()
	{
		int n,k;
		cin>>n;
		cin>>k;
		memset(dp,0x3f,sizeof(dp));
		for(int i=1;i<=n;i++) cin>>su[i];
		sort(a+1,a+n+1);
		for(int i=2;i<=n;i++) su[i]+=su[i-1];
		for(int i=0;i<=n;i++) dp[1][i]=sum(1,i);
		for(int i=2;i<=k;i++) dfs(1,n,i-1,n,i);
		cout<<dp[k][n];
	}
}
signed main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0),cout.tie(0);
	return Qaaxaap::work(),0;
}

