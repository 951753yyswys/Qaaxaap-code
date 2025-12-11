#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace DS
{
	template<typename T> 
	class linkedlist
	{
	public:
		int siz=0,__begin,__end;
	private:
		struct node
		{
			T num;
			int nxt,pre;
			node()=default;
			~node()=default;
		};
		vector<node> a;
		void _mknode(int fa,T val)
		{
			a.push_back(node());
			a[fa].nxt=siz;
			a[siz].pre=fa;
			a[siz].num=val;
			siz++;
		}
		void _insert(int fa,int son,T val)
		{
			a.push_back(node());
			a[fa].nxt=siz;
			a[son].pre=siz;
			a[siz].pre=fa;
			a[siz].nxt=son;
			a[siz].num=val;
			siz++;
		}
	public:
		linkedlist()
		{
			siz=2;
			a.resize(2);
			__begin=0;
			__end=1;
			a[0].nxt=1;
			a[1].pre=0;
			a[1].nxt=1;
		}
		~linkedlist()=default;
		void push_back(T val){_insert(a[__end].pre,__end,val);}
		void remove(int id)
		{
			int now=id;
			if(now==__end||now==__begin) return;
			a[a[now].pre].nxt=a[now].nxt;
			a[a[now].nxt].pre=a[now].pre;
		}
		int prev(int id){return a[id].pre;}
		int next(int id){return a[id].nxt;}
		int begin(){return __begin;}
		int end(){return __end;}
		T val(int it){return a[it].num;}
		T valn(int it){return a[a[it].nxt].num;}
		T valp(int it){return a[a[it].pre].num;}
	};
}
using namespace DS;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		int n,pos;
		cin>>s>>pos;
		n=s.size();
		if(n==1)
		{
			cout<<s;
			continue;
		}
		s='#'+s;
		int len=n,rnk,sum=0;
		while(sum<pos)
		{
			sum+=len;
			len--;
		}
		len++;
		int ed=n-len;
		//cout<<"(len,ed) "<<len<<' '<<ed<<endl;
		rnk=len-(sum-pos);
		//cout<<"rnk:"<<rnk<<endl;
		linkedlist<char> a;
		for(int i=1;i<=n;i++) a.push_back(s[i]);
		int now=a.next(a.begin());
		while(a.next(now)!=a.end()&&a.val(now)<=a.val(a.next(now))) now=a.next(now);
		//cout<<"valnow:"<<(char)a.val(now)<<endl;
		while(ed)
		{
			now=a.prev(now);
			bool flag=0;
			while(a.next(now)!=a.end()) 
			{
				if(a.val(now)>a.valn(now))
				{
					int rm=now;
					now=a.next(now);
					a.remove(rm);
					ed--;
					flag=1;
					break;
				}
				now=a.next(now);
			}
			if(flag) continue;
			break;
		}
		int ans=a.begin();
		for(int i=1;i<=rnk;i++) ans=a.next(ans);
		cout<<(char)a.val(ans);
	}
	return 0;
}
