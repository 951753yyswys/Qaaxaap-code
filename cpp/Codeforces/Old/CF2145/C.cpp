#include<bits/stdc++.h>
using namespace std;
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        string s;
        cin>>n>>s;
        int cnta=0,cntb=0;
        for(char c:s) 
        {
            if(c=='a') cnta++;
            else cntb++;
        }
        if(cnta==cntb) 
        {
            cout<<"0\n";
            continue;
        }
        int tg=cnta-cntb;
        map<int,int> ff;
        ff[0]=-1;  
        int csum=0;
        int mlen=INT_MAX;
        for(int i=0;i<n;i++) 
        {
            if(s[i]=='a') csum++;
            else csum--;
            int ned=csum-tg;
            if(ff.find(ned)!=ff.end()) 
            {
                int st=ff[ned]+1;
                int len=i-st+1;
                if(len<n) mlen=min(mlen,len);
            }
            ff[csum]=i;
        }
        if(mlen==INT_MAX) cout<<"-1\n";
        else cout<<mlen<<"\n";
    }
    return 0;
}