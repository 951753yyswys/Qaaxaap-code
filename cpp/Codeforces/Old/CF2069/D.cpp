#include<bits/stdc++.h>
using namespace std;
int sum[26][200020],ls[26];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n=s.size();
        s='#'+s;
        for(int k=0;k<26;k++) sum[k][0]=0; 
        for(int i=1;i<=n;i++) 
        {
            for(int k=0;k<=25;k++) sum[k][i]=sum[k][i-1];
            sum[s[i]-'a'][i]++;
        }
        int sm=1;
        while(s[sm]==s[n-sm+1]&&sm<=n/2) sm++;
        if(sm==n/2+1) 
        {
            cout<<0<<endl;
            continue;
        }
        int ans=2*(n/2-(sm-1));
        for(int i=0;i<26;i++) ls[i]=sum[i][n-sm+1]-sum[i][sm-1];
        int ansl=0;
        while(ansl<=n-sm+1)
        {
            int flag=1;
            for(int k=0;k<26;k++)
            {
                if((sum[k][n/2+ansl]-sum[k][sm-1])*2<ls[k]) flag=0;
            }
            if(flag) break;
            ansl++;
        }
        int ansr=0;
        while(n/2-ansr+1>=sm)
        {
            int flag=1;
            for(int k=0;k<26;k++)
            {
                if((sum[k][n-sm+1]-sum[k][n/2-ansr])*2<ls[k]) flag=0;
            }
            if(flag) break;
            ansr++;
        }
        //cout<<sm<<" "<<ansl<<' '<<ansr<<endl;
        int flagl=0,flagr=0;
        if(ansl==0) flagl=1;
        if(ansr==0) flagr=1;
        ansl+=n/2-sm+1;
        ansr+=n/2-sm+1;
        //cout<<ansl<<' '<<ansr<<endl;
        int mid=n/2;
        if(flagl==1) while(s[mid]==s[n-mid+1]) mid--,ansl--;
        if(flagr==1) while(s[mid]==s[n-mid+1]) mid--,ansr--;
        ans=min({ans,ansl,ansr});
        cout<<ans<<endl;
    }
    return 0;
}