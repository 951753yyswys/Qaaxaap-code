#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
	int l,r,sum,jlz,clz;
} t[8000001];
int a[2000001],mod=998244353;
void mak(int ro,int l,int r)
{
	t[ro].l=l;
	t[ro].r=r;
	t[ro].sum=0;
	t[ro].jlz=0;
	t[ro].clz=1;
	if(l==r) 
	{
		t[ro].sum=a[l]%mod;
		return;
	}
	int mid=(l+r)/2;
	mak(ro*2,l,mid);
	mak(ro*2+1,mid+1,r);
	t[ro].sum=(t[ro*2].sum+t[ro*2+1].sum)%mod;
}
void pushdown(int ro)
{
	int ll=t[ro*2].r-t[ro*2].l+1;
	int rl=t[ro*2+1].r-t[ro*2+1].l+1;
	t[ro*2].sum=(t[ro].clz*t[ro*2].sum+t[ro].jlz*ll)%mod;
	t[ro*2+1].sum=(t[ro].clz*t[ro*2+1].sum+t[ro].jlz*rl)%mod;
	t[ro*2].clz=(t[ro].clz*t[ro*2].clz)%mod;
	t[ro*2+1].clz=(t[ro].clz*t[ro*2+1].clz)%mod;
	t[ro*2].jlz=(t[ro*2].jlz*t[ro].clz+t[ro].jlz)%mod;
	t[ro*2+1].jlz=(t[ro*2+1].jlz*t[ro].clz+t[ro].jlz)%mod;
	t[ro].jlz=0;
	t[ro].clz=1;
}
void cchanc(int ro,int l,int r,int s)
{
	if(t[ro].l>=l&&t[ro].r<=r)
	{
		t[ro].clz=t[ro].clz*s%mod;
		t[ro].sum=t[ro].sum*s%mod;
		t[ro].jlz=t[ro].jlz*s%mod;
		return;
	}
	pushdown(ro);
	if(t[ro*2].r>=l) cchanc(ro*2,l,r,s);
	if(t[ro*2+1].l<=r) cchanc(ro*2+1,l,r,s);
	t[ro].sum=(t[ro*2].sum+t[ro*2+1].sum)%mod;
}
void jchanc(int ro,int l,int r,int s)
{
	if(t[ro].l>=l&&t[ro].r<=r)
	{
		t[ro].jlz=(t[ro].jlz+s)%mod;
		t[ro].sum=(t[ro].sum+s*(t[ro].r-t[ro].l+1))%mod;
		return;
	}
	pushdown(ro);
	if(t[ro*2].r>=l) jchanc(ro*2,l,r,s);
	if(t[ro*2+1].l<=r) jchanc(ro*2+1,l,r,s);
	t[ro].sum=(t[ro*2].sum+t[ro*2+1].sum)%mod;
}
int fin(int ro,int l,int r)
{
	if(t[ro].l>=l&&t[ro].r<=r) return t[ro].sum;
	if(t[ro].r<l||t[ro].l>r) return 0;
	pushdown(ro);
	int ans=0;
	if(t[ro*2].r>=l) ans=(ans+fin(ro*2,l,r))%mod;
	if(t[ro*2+1].l<=r) ans=(ans+fin(ro*2+1,l,r))%mod;
	return ans%mod;
}
signed main()
{
	ios::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) a[i]=1;
	mak(1,1,n);
	for(int i=1;i<=m;i++)
	{
        int x,y;
        cin>>x>>y;
        int ans=fin(1,1,x);
        cout<<ans<<endl;
        jchanc(1,y,y,ans);
        cchanc(1,1,x,0);
	}
	return 0;
}