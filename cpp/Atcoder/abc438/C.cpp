#include<bits/stdc++.h>
#define int long long
using namespace std;
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
        };
        int cnt,root;
        tree t[101010];

        inline int get_height(int ro) { return t[ro].height; }

        inline int get_balance(int ro) { return get_height(t[ro].l)-get_height(t[ro].r); }

        inline void update_height(int ro)
        {
            t[ro].height=max(get_height(t[ro].l),get_height(t[ro].r))+1;
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
            int ro=++cnt;
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
                int left_size=t[t[ro].l].siz;
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
namespace Qaaxaap
{
	void work1()
	{
		int n;
		cin>>n;
		//AVL<pair<int,int>> tr;
		set<pair<pair<int,int>,int>> tr;
		for(int i=1;i<=n;i++) 
		{
			int a;
			cin>>a;
			auto ed=(*prev(tr.end()));
			if(!tr.empty()&&ed.second==a)
			{
				tr.erase(prev(tr.end()));
				ed.first.second=i;
				tr.insert(ed);
			}
			tr.insert(make_pair(make_pair(i,i),a));
		}
		int siz=n;
		for(int i=1;i<=siz-3;i++)
		{
			
		}
	}
	void work()
	{
		int n;
		cin>>n;
		vector<int> st(n+1);
		int tp=0;
		for(int i=1;i<=n;i++)
		{
			int a;
			cin>>a;
			st[++tp]=a;
			while(tp>=4&&st[tp]==st[tp-1]&&st[tp-1]==st[tp-2]&&st[tp-2]==st[tp-3]) tp-=4;
		}
		cout<<tp;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

