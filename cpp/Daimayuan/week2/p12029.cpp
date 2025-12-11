#include<bits/stdc++.h>
using namespace std;
namespace Qaaxaap
{
	int n;
	struct tup
	{
		int num,mi,mx,prf;
		tup(int a,int b,int c){num=a,mi=b,mx=c,prf=mx;};
	};
	void solve(list<tup>&has)
	{
		int tim=clock();
		/*if(0)
		{
			for(auto tmp:has) cout<<tmp.num<<' '<<tmp.mx<<endl;
			cout<<"OVER"<<endl;
		}*/
		int nh=has.size(),mx=prev(has.end())->num;
		prev(has.end())->prf=prev(has.end())->mx;
		for(auto it=prev(prev(has.end()));;it--) 
		{
			it->prf=max(it->mx,next(it)->prf);
			if(it==has.begin()) break;
		}
		int ans=0;
		auto r=has.end();
		for(auto l=has.begin();l!=has.end();l++)
		{
			while(r!=has.begin()&&prev(r)->num+l->num>=mx) r--;
			if(r->num+l->num<mx) continue;
			/*if(0)
			{
				cout<<"l,r: ";
				cout<<"hasl,r: ";
				cout<<l->num<<' '<<r->num<<endl;
				cout<<"mi,mx: ";
				//cout<<*buc[l->num].begin()<<' '<<prf[r->num]<<endl;
			}*/
			ans=max(ans,abs(r->prf-l->mi));
		}
		cout<<ans<<endl;
		//assert(((clock()-tim)*1.0/CLOCKS_PER_SEC)<=1.00/n);
	}
	void print(vector<int> &get,vector<set<int>> &buc)
	{
		cout<<"START:"<<endl;
		for(auto tmp:get) cout<<tmp<<' ';
		cout<<endl;
		for(auto tmp:buc)
		{
			for(auto tmp1:tmp) cout<<tmp1<<' ';
			cout<<endl;
		}
	}
	const int N=5e5+5,mod=998244353;
	void work()
	{
		int q;
		cin>>n>>q;
		vector<int> a(n+1),get(n+1),mii(n+1,0x7fffffff),mxx(n+1,0);
		for(int i=1;i<=n;i++) cin>>a[i],get[a[i]]++;
		int tim=clock();
		vector<set<int>> buc(n+1);
		for(int i=1;i<=n;i++) buc[get[i]].insert(i),mii[get[i]]=min(mii[get[i]],i),mxx[get[i]]=max(mxx[get[i]],i);
		list<tup> has;
		for(int i=1;i<=n;i++) if(mxx[i]) has.push_back(tup(i,mii[i],mxx[i]));
		//assert(((clock()-tim)*1.0/CLOCKS_PER_SEC)<=0.5);
		while(q--)
		{
			int id,x;
			int ch1,ch2;
			cin>>id>>x;
			int tim=clock();
			if(a[id]==x)
			{
				solve(has);
				continue;
			}
			buc[get[a[id]]].erase(a[id]);
			ch1=get[a[id]];
			get[a[id]]--;
			buc[get[a[id]]].insert(a[id]);
			buc[get[x]].erase(x);
			ch2=get[x]+1;
			get[x]++;
			a[id]=x;
			buc[get[x]].insert(x);
			for(auto it=has.begin();it!=has.end();)
			{
				int tmp=it->num;
				if(tmp==ch1||tmp==ch2-1) 
				{
					if(buc[tmp].empty()) 
					{
						it++;
						has.erase(prev(it));
						continue;
					}
				}
				it++;
			}
			for(auto it=next(has.begin());it!=has.end();it++)
			{
				int tmp=it->num;
				if(tmp>ch1-1&&prev(it)->num<ch1-1) has.insert(it,tup(ch1-1,0,0));
				if(tmp>ch2&&prev(it)->num<ch2) has.insert(it,tup(ch2,0,0));
			}
			if(prev(has.end())->num<min(ch1-1,ch2)) has.insert(has.end(),tup(min(ch2,ch1-1),0,0));
			if(prev(has.end())->num<max(ch1-1,ch2)) has.insert(has.end(),tup(max(ch2,ch1-1),0,0));
			for(auto it=has.begin();it!=has.end();it++)
			{	
				int tmp=it->num;
				if(tmp==ch1||tmp==ch2||tmp==ch1-1||tmp==ch2-1) *it=tup(tmp,*buc[tmp].begin(),*prev(buc[tmp].end()));
			}
			assert(has.size()<=2*sqrt(n));
			//print(get,buc);;
			//assert(((clock()-tim)*1.0/CLOCKS_PER_SEC)<=1.00/n);
			solve(has);
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	return Qaaxaap::work(),0;
}
