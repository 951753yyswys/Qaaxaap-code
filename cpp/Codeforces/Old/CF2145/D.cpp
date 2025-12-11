#include<bits/stdc++.h>
using namespace std;
const int mxn=30;
const int mxs=465; 
bool dp[31][466];
int pseg[31][466];
void init() 
{
    dp[0][0]=1;
    for(int i=0;i<=mxn;i++) 
    {
        for(int j=0;j<=mxs;j++) 
        {
            if(dp[i][j]) 
            {
                for(int l=1;l<=mxn-i;l++) 
                {
                    int nj=j+l*(l+1)/2;
                    if(nj<=mxs) 
                    {
                        dp[i+l][nj]=1;
                        pseg[i+l][nj]=l;
                    }
                }
            }
        }
    }
}

int main() 
{
    init();
    int t;
    cin>>t;
    while(t--) 
    {
        int n,k;
        cin>>n>>k;
        int sums=n*(n-1)/2;
        int S=n*(n+1)/2-k;
        if(S<n||S>n*(n+1)/2||!dp[n][S]) cout<<0<<endl; 
        else 
        {
            vector<int> segs;
            int li=n,lj=S;
            while(li>0) 
            {
                int l=pseg[li][lj];
                segs.push_back(l);
                li-=l;
                lj-=l*(l+1)/2;
            }
            reverse(segs.begin(), segs.end());
            vector<int> nums(n);
            for(int i=0;i<n;i++) nums[i]=i+1;
            vector<int> ans;
            for(int len:segs) 
            {
                vector<int> sum(nums.end()-len,nums.end());
                ans.insert(ans.end(),sum.begin(),sum.end());
                nums.erase(nums.end()-len,nums.end());
            }
            for(int i=0;i<n;i++) 
            {
                if(i>0) cout<<' ';
                cout<<ans[i];
            }
            cout<<'\n';
        }
    }
    return 0;
}