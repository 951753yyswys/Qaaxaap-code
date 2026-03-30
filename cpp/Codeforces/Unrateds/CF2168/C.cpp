#include <bits/stdc++.h>
#define int long long
using namespace std;
int nums[]={3,5,6,7,9,10,11,12,13,14,15,17,18,19,20};
int chks[]={1,2,4,8,16};
signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string opt;
    cin>>opt;
    if(opt=="first") 
    {
        int t;
        cin>>t;
        for(int i=0;i<t;i++) 
        {
            int x;
            cin>>x;
            int u=x-1;
            vector<bool> dzd(15,0);
            for(int j=0;j<15;j++) 
                dzd[j]=(u>>j)&1;
            vector<bool> p(5,0);
            for(int j=0;j<15;j++) 
            {
                int tmp=nums[j];
                for(int k=0;k<5;k++) 
                {
                    if(tmp&(1<<k))
                        p[k]=p[k]^dzd[j];
                }
            }
            vector<int> S;
            for(int j=0;j<15;j++)
                if(dzd[j])
                    S.push_back(nums[j]);
            for(int j=0;j<5;j++)
                if(p[j])
                    S.push_back(chks[j]);
            cout<<S.size()<<endl;
            if(!S.empty()) 
            {
                for(int tmp:S)
                    cout<<tmp<<" ";
                cout<<endl;
            }
        }
    } 
    else if(opt=="second") 
    {
        int t;
        cin>>t;
        for(int i=0;i<t;i++) 
        {
            int n;
            cin>>n;
            vector<int> dzd(n);
            for(auto &tmp:dzd) 
                cin>>tmp;
            vector<bool> c(21,0);
            for(auto tmp:dzd)
                c[tmp]=1;
            vector<bool> s(5,0);
            for(int tmp=1;tmp<=20;tmp++) 
                if(c[tmp])
                    for(int k=0;k<5;k++)
                        if(tmp&(1<<k))
                            s[k]=s[k]^1;
            int tril=0;
            for(int k=0;k<5;k++)
                if(s[k])
                    tril|=(1<<k);
            if (tril!=0&&tril>=1&&tril<=20) 
                c[tril]=!c[tril];
            int u=0;
            for(int j=0;j<15;j++) 
                if (c[nums[j]]) 
                    u|=(1<<j);
            int x=u+1;
            cout<<x<<endl;
        }
    }
    
    return 0;
}