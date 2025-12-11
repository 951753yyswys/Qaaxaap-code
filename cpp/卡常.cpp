#include<bits/stdc++.h>
using namespace std;

namespace IO{
        #ifndef LOCAL
            constexpr auto maxn = 1 << 20;
            char in[maxn], out[maxn], *p1 = in, *p2 = in, *p3 = out;
            #define getchar() (p1 == p2 && (p2 = (p1 = in) + fread(in, 1, maxn, stdin), p1 == p2) ? EOF : *p1++)
            #define flush() (fwrite(out, 1, p3 - out, stdout))
            #define putchar(x) (p3 == out + maxn && (flush(), p3 = out), *p3++ = (x))
            class Flush{public: ~Flush(){flush();}}_;
        #endif
        namespace usr{
            template <typename type>
            inline type read(type &x){x = 0; bool flag(0); char ch = getchar(); while(!isdigit(ch)) flag ^= ch == '-', ch = getchar(); while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar(); return flag ? x = -x : x;}
            template <typename type>
            inline void write(type x){x < 0 ? x = -x, putchar('-') : 0; static short Stack[50], top(0); do Stack[++top] = x % 10, x /= 10; while(x); while(top) putchar(Stack[top--] | 48);}
            inline char read(char &x){do x = getchar(); while(isspace(x)); return x;}
            inline char write(const char &x){return putchar(x);}
            inline void read(char *x){static char ch; read(ch); do *(x++) = ch; while(!isspace(ch = getchar()) && ~ch);}
            template <typename type> inline void write(type *x){while(*x) putchar(*(x++));}
            inline void read(std::string &x){static char ch; read(ch), x.clear(); do x += ch; while(!isspace(ch = getchar()) && ~ch);}
            inline void write(const std::string &x){for(int i = 0, len = x.length(); i < len; ++i)putchar(x[i]);}
            template <typename type, typename...T> inline void read(type &x, T&...y){read(x), read(y...);}
            template <typename type, typename...T>
            inline void write(const type &x, const T&...y){write(x), putchar(' '), write(y...), sizeof...(y) ^ 1 ? 0 : putchar('\n');}
            template <typename type>
            inline void put(const type &x, bool flag = 0){write(x), flag ? putchar('\n') : putchar(' ');}
        }
        #ifndef LOCAL
            #undef getchar
            #undef flush
            #undef putchar
        #endif
    } using namespace IO::usr;

namespace DS {
    template<typename T>
    class AVL {
    private:
        static const int MAXN = 100010;
        struct Node {
            int l,r,fa,height,siz;
            T val;
        };
        Node t[MAXN];
        int cnt, root, pool[MAXN], pool_top;
        
        inline int new_node(T x) {
            int ro = pool_top ? pool[pool_top--] : ++cnt;
            t[ro] = {0,0,0,1,1,x};
            return ro;
        }
        
        inline void delete_node(int ro) {
            pool[++pool_top] = ro;
        }
        
        inline void update_height(int ro) {
            t[ro].height = max(t[t[ro].l].height, t[t[ro].r].height) + 1;
            t[ro].siz = t[t[ro].l].siz + t[t[ro].r].siz + 1;
        }
        
        inline int get_balance(int ro) {
            return t[t[ro].l].height - t[t[ro].r].height;
        }
        
        inline void left_rotate(int ro) {
            int fa = t[ro].fa, rson = t[ro].r;
            t[ro].r = t[rson].l;
            if(t[rson].l) t[t[rson].l].fa = ro;
            t[rson].l = ro;
            t[ro].fa = rson;
            t[rson].fa = fa;
            if(fa) (t[fa].l == ro ? t[fa].l : t[fa].r) = rson;
            else root = rson;
            update_height(ro);
            update_height(rson);
        }
        
        inline void right_rotate(int ro) {
            int fa = t[ro].fa, lson = t[ro].l;
            t[ro].l = t[lson].r;
            if(t[lson].r) t[t[lson].r].fa = ro;
            t[lson].r = ro;
            t[ro].fa = lson;
            t[lson].fa = fa;
            if(fa) (t[fa].l == ro ? t[fa].l : t[fa].r) = lson;
            else root = lson;
            update_height(ro);
            update_height(lson);
        }
        
        inline void balance(int ro) {
            for(; ro; ro = t[ro].fa) {
                update_height(ro);
                int bf = get_balance(ro);
                if(bf > 1) {
                    if(get_balance(t[ro].l) < 0) left_rotate(t[ro].l);
                    right_rotate(ro);
                } else if(bf < -1) {
                    if(get_balance(t[ro].r) > 0) right_rotate(t[ro].r);
                    left_rotate(ro);
                }
            }
        }
        
        inline void add_private(T x) {
            if(!root) { root = new_node(x); return; }
            
            int now = root, parent = 0;
            while(now) {
                parent = now;
                now = (x < t[now].val ? t[now].l : t[now].r);
            }
            
            int new_ro = new_node(x);
            t[new_ro].fa = parent;
            (x < t[parent].val ? t[parent].l : t[parent].r) = new_ro;
            balance(parent);
        }
        
        inline int find_min(int ro) {
            while(t[ro].l) ro = t[ro].l;
            return ro;
        }
        
        inline void transplant(int u, int v) {
            if(!t[u].fa) root = v;
            else (t[t[u].fa].l == u ? t[t[u].fa].l : t[t[u].fa].r) = v;
            if(v) t[v].fa = t[u].fa;
        }
        
        inline void del_private(T x) {
            int now = root;
            while(now && t[now].val != x)
                now = (x < t[now].val ? t[now].l : t[now].r);
            
            if(!now) return;
            int to_delete = now, balance_start;
            
            if(!t[now].l) {
                balance_start = t[now].fa;
                transplant(now, t[now].r);
            } else if(!t[now].r) {
                balance_start = t[now].fa;
                transplant(now, t[now].l);
            } else {
                int successor = find_min(t[now].r);
                balance_start = (t[successor].fa != now ? t[successor].fa : successor);
                
                if(t[successor].fa != now) {
                    transplant(successor, t[successor].r);
                    t[successor].r = t[now].r;
                    t[t[successor].r].fa = successor;
                }
                transplant(now, successor);
                t[successor].l = t[now].l;
                t[t[successor].l].fa = successor;
            }
            
            delete_node(to_delete);
            balance(balance_start);
        }
        inline int query_value_to_rank(T x) {
            int ro = root, rank = 1;
            while(ro) {
                if(x <= t[ro].val) ro = t[ro].l;
                else {
                    rank += t[t[ro].l].siz + 1;
                    ro = t[ro].r;
                }
            }
            return rank;
        }
        
        inline T query_rank_to_value(int rank) {
            int ro = root;
            while(ro) {
                int left_size = t[t[ro].l].siz;
                if(rank <= left_size) ro = t[ro].l;
                else if(rank == left_size + 1) return t[ro].val;
                else rank -= left_size + 1, ro = t[ro].r;
            }
            return T{};
        }
        
        inline T query_pre(T x) {
            int ro = root; T pre = T{};
            while(ro) {
                if(t[ro].val < x) pre = t[ro].val, ro = t[ro].r;
                else ro = t[ro].l;
            }
            return pre;
        }
        
        inline T query_suc(T x) {
            int ro = root; T suc = T{};
            while(ro) {
                if(t[ro].val > x) suc = t[ro].val, ro = t[ro].l;
                else ro = t[ro].r;
            }
            return suc;
        }
        
    public:
        AVL() : cnt(0), root(0), pool_top(0) {}
        inline void add(T x) { add_private(x); }
        inline void del(T x) { del_private(x); }
        inline int qur(T x) { return query_value_to_rank(x); }
        inline T quv(int x) { return query_rank_to_value(x); }
        inline T pre(T x) { return query_pre(x); }
        inline T suc(T x) { return query_suc(x); }
    };
};

using namespace DS;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    AVL<int> dzd;
    int n,t,tmp; read(n,t);
    for(int i=1;i<=n;++i) read(tmp),dzd.add(tmp);
    int lst=0,ans=0;
    while(t--) {
        int opt, x; read(opt,x); 
        switch(opt) {
            case 1: dzd.add(x^lst); break;
            case 2: dzd.del(x^lst); break;
            case 3: lst=dzd.qur(x^lst),ans^=lst; break;
            case 4: lst=dzd.quv(x^lst),ans^=lst; break;
            case 5: lst=dzd.pre(x^lst),ans^=lst; break;
            case 6: lst=dzd.suc(x^lst),ans^=lst; break;
        }
    }
    put(ans,0);
    return 0;
}