#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    using ull = unsigned long long;
    const ull base = 911382323ULL;
    const int MAXL = 1000000 + 5;
    ull powb[MAXL];
    string pr(const string &s) 
    {
        int n=s.size();
        vector<int> pi(n);
        for(int i=1;i<n;i++) 
        {
            int j=pi[i-1];
            while(j>0&&s[i]!=s[j]) j=pi[j-1];
            if(s[i]==s[j]) j++;
            pi[i]=j;
        }
        if(n%(n-pi[n-1])==0) return s.substr(0,n-pi[n-1]);
        return s;
    }
    int cmp(const string &a, const string &b) 
    {
        int na=a.size(),nb=b.size();
        int len=na+nb;
        for(int i=0;i<len;i++) 
        {
            char ca=(i<na?a[i]:b[i-na]);
            char cb=(i<nb?b[i]:b[i-nb]);
            if(ca!=cb) return (ca<cb?-1:1);
        }
        return 0;
    }
    void work()
    {
        powb[0]=1;
        for(int i=1;i<MAXL;i++) powb[i]=powb[i-1]*base;
        int T;
        cin>>T;
        while(T--) 
        {
            int n;
            cin>> n;
            vector<string> s(n);
            for(int i=0;i<n;i++) cin>>s[i];
            unordered_map<string,int> rc;
            bool flag=0;
            for(int i=0;i<n;i++) 
            {
                string r=pr(s[i]);
                int &c=rc[r];
                c++;
                if(c>=2) flag=1;
            }
            vector<string> a=s;
            sort(a.begin(),a.end(),[](const string &x,const string &y){return cmp(x,y)<0;});
            vector<int> start(n);
            int totalLen=0;
            for(int i=0;i<n;i++) 
            {
                start[i]=totalLen;
                totalLen+=a[i].size();
            }
            string b;
            for(int i=0;i<n;i++) b+=a[i];
            if(flag) 
            {
                cout<<b<<endl;
                continue;
            }
            int M=n-1;      
            int L=totalLen;       
            vector<ull> HB(L+1);
            HB[0]=0;
            for(int i = 0; i < L; ++i) 
                HB[i + 1] = HB[i] * base + (ull)(b[i] - 'a' + 1);
            auto hashB = [&](int l, int r) -> ull {
                return HB[r] - HB[l] * powb[r - l];
            };
            struct Cand 
            {
                int l;          
                int len;  
                string alt;          
                vector<ull> H;
            };
            vector<Cand> cand(M);
            for(int i=0;i<M;i++) 
            {
                cand[i].l=start[i];
                cand[i].alt=a[i+1]+a[i];
                cand[i].len=cand[i].alt.size();
                int lenY=cand[i].len;
                cand[i].H.assign(lenY+1,0);
                for(int k=0;k<lenY;k++) cand[i].H[k+1]=cand[i].H[k]*base+(ull)(cand[i].alt[k]-'a'+1);
            }
            auto hash_prefix = [&](int idx, int len) -> ull {
                // hash of T_idx[0..len)
                int l = cand[idx].l;
                int lenY = cand[idx].len;
                int r = l + lenY;

                if (len <= l) {
                    // 完全在左侧原始部分
                    return hashB(0, len);
                } else if (len <= r) {
                    // 截断在替换段内部
                    ull h_before = hashB(0, l);           // b[0..l)
                    ull h_alt = cand[idx].H[len - l];     // alt[0..len-l)
                    return h_before * powb[len - l] + h_alt;
                } else {
                    // 覆盖整个替换段再加一部分右侧
                    ull h_before = hashB(0, l);           // b[0..l)
                    ull h_afull = cand[idx].H[lenY];      // alt[0..lenY)
                    ull h12 = h_before * powb[lenY] + h_afull; // 长度 r
                    ull h_suf = hashB(r, len);            // b[r..len)
                    return h12 * powb[len - r] + h_suf;
                }
            };

            auto charAt = [&](int idx, int pos) -> char {
                int l = cand[idx].l;
                int lenY = cand[idx].len;
                int r = l + lenY;
                if (pos < l || pos >= r) return b[pos];
                return cand[idx].alt[pos - l];
            };

            auto lessCand = [&](int i, int j) -> bool {
                // 比较候选 T_i 与 T_j
                int low = 0, high = L;
                while (low < high) {
                    int mid = (low + high + 1) >> 1;
                    if (hash_prefix(i, mid) == hash_prefix(j, mid))
                        low = mid;
                    else
                        high = mid - 1;
                }
                int lcp = low;
                if (lcp == L) return 0; 
                char ci = charAt(i, lcp);
                char cj = charAt(j, lcp);
                return ci < cj;
            };

            int best = 0;
            for (int i = 1; i < M; ++i) {
                if (lessCand(i, best)) best = i;
            }
            int k=best;
            string ans;
            for(int i=0;i<n;i++) 
            {
                if(i==k) ans+=a[k+1];
                else if(i==k+1) ans+=a[k];
                else ans+=a[i];
            }
            cout<<ans<<endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    return Qaaxaap::work(),0;
}