#include<bits/stdc++.h>
using namespace std;
namespace DS
{
	using ll=long long;
	template<typename T>
	class linkedlist
	{
	private:
		int siz;
		struct node
		{
			T num;
			unique_ptr<node> lst;
			node(T newnum){num=newnum;}
			node()=default;
			~node()=default;
		};
		using uniL=unique_ptr<node>;
		T _query(uniL& ro,int x)
		{
			if(ro==nullptr) return T{};
			if(x<=0) return ro->num;
			return _query(ro->lst,--x);
		}
		T* _query_ptr(uniL& ro,int x)
		{
			if(ro==nullptr) return nullptr;
			if(x<=0) return &(ro->num);
			return _query_ptr(ro->lst,--x);
		}
		void _update(uniL& ro,int x,T num)
		{
			if(ro==nullptr) return;
			if(x<=0) return void(ro->num=num);
			return void(_update(ro->lst,--x,num));
		}
		void _push_back(uniL& ro,T x)
		{
			if(ro->lst==nullptr) ro->lst=make_unique<node>(x),siz++; 
			else _push_back(ro->lst,x);
		}
		void _insert(uniL& ro,int rank,T val)
		{
			if(ro==nullptr) return;
			rank--;
			if(rank<=0) 
			{
				uniL tmp=make_unique<node>(val);
				tmp->lst=move(ro->lst);
				ro->lst=move(tmp);
				siz++;
				return;
			}
			_insert(ro->lst,rank,val);
		}
	public:
		uniL hd=nullptr;
		linkedlist(){hd=make_unique<node>();};
		~linkedlist()=default;
		T query(int x){return _query(hd,x);}
		T* query_ptr(int x){return _query_ptr(hd,x);}
		void update(int x,T num){_update(hd,x,num);}
		void insert(int x,T num){_insert(hd,x,num);}
		void push_back(int x){_push_back(hd,x);}
		int size(){return siz;}
	};
	class block_val
	{
	private:
		int cnt[70005],blcnt[268];
		const int len=264,blnum=266;
		inline int belong(int x){return (x-1)/len+1;}
	public:
        block_val()=default;
        ~block_val()=default;
        void insert(int x)
        {
            cnt[x]++;
            blcnt[belong(x)]++;
        }
        void prefix()
        {
            for(int i=1;i<=70000;i++) cnt[i]=cnt[i-1]+cnt[i];
            for(int i=2;i<=blnum;i++) blcnt[i]+=blcnt[i-1];
        }
        void clear()
        {
            for(int i=0;i<=70000;i++) cnt[i]=0;
            for(int i=1;i<=blnum;i++) blcnt[i]=0;
        }
	};
    class blocklist
    {
    private:
        int siz,len,blnum,hd,ed;
        int belong(int x){return (x-1)/len+1;}
		vector<node> t;
        struct node
        {
            int siz;
            linkedlist<int> lis;
            block_val val;
			int nxt,pre;
        };
    public:
        blocklist(vector<int> &y)
        {
            hd=0;
			ed=1;
			t.resize(2);
			t[0].nxt=1;
			t[1].nxt=1;
			t[1].pre=0;
            siz=y.size();
            len=sqrt(siz)+1;
            blnum=belong(siz);
        }
    };
}
int main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0),cout.tie(0);
	
	return 0;
}

