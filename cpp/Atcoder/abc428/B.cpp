#include<bits/stdc++.h>
using namespace std;
int mx,k;
string ys;
vector<string> ans;
int count(string s,string t)
{
    s='#'+s;
    t='#'+t;
    int cnt=0;
    int ls=s.size()-1;
    int lt=t.size()-1;
    for(int i=1;i+lt-1<=ls;i++)
    {
        int flag=1;
        for(int j=1;j<=lt;i++) if(s[i]!=t[j]) flag=0;
        cnt+=flag;
    }
    return cnt;
}
void dfs(string s)
{
    if(s.size()==k) 
    {
        int cnt=count(ys,s);
        if(cnt==mx) ans.push_back(s);
        if(cnt>mx) 
        {
            ans.clear();
            ans.push_back(s);
        } 
    }
    string ls1=s;
    for(char i='a';i<='z';i++)
        dfs(ls1+i);
}
int main()
{
    int n,k;
    cin>>n>>k;
    cin>>ys;
    dfs("");
    return 0;
}