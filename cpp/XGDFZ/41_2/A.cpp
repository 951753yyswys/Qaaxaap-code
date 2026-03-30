#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    queue<int> ans,tmp;
    for(int i=1;i<=n;i++) ans.push(i);
    int k;
    while(k>=ans.size())
    {
        int cnt=0;
        while(!ans.empty())
        {
            cnt++;
            if(cnt<=k) 
            {
                ans.pop();
            }
            else 
            {
                tmp.push(ans.front());
                ans.pop();
            }
            
        }
    }
    return 0;
}