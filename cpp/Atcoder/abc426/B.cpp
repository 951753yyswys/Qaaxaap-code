#include<bits/stdc++.h>
using namespace std;
int t[1010];
int main()
{
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++) t[s[i]-'a']++;
    for(int i=0;i<='z'-'a';i++) 
    {
        if(t[i]==1) cout<<char(i+'a');
    } 
    return 0;
}