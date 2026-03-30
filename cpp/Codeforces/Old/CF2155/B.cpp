// #include<bits/stdc++.h>
// using namespace std;
// int mp[101][101];
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int n,k;
//         cin>>n>>k;
//         if(k==n*n-1)
//         {
//             cout<<"NO"<<endl;
//             continue;
//         }
//         for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) mp[i][j]=1;
//         int num=0,li,lj;
//         for(int i=1;i<=n,num<k;i++)
//         {
//             for(int j=2;j<=n,num<k;j++) 
//             {
//                 if(j==2) num+=2;
//                 else num++;
//                 li=i;
//                 lj=j;
//                 mp[i][j]=3;
//             }
//         }
//         if(li==0)
//         {
//             cout<<"No"<<endl;
//             continue;
//         }
//         if(num>k) mp[li-1][n]=1;
//         cout<<"yes"<<endl;
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=n;j++) 
//             {
//                 if(mp[i][j]==1) cout<<"U";
//                 else cout<<"D";
//             }
//             cout<<endl;
//         }
//     }
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
char mp[101][101];
int main() 
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n,k;
        cin>>n>>k;
        if(k==n*n-1) 
        {
            cout<<"NO"<<endl;
            continue;
        }
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) mp[i][j]='L';
        if(k!=n*n)
        {
            k=n*n-k;
            //cout<<k<<endl;
            int num=0;
            // while(k>1)
            // {
            //     int d=min(k,n);
            //     mp[num][d-1]='L';
            //     num++;
            //     k-=d;
            // }
            // if(k==1) mp[num-1][n-1]='R',mp[num-1][n-2]='L',mp[num][1]='L';
            int en=1;
            for(int i=0;i<n;i++) mp[0][i]='R';
            while(k>1&&en<n)
            {
                mp[0][en]='L';
                mp[0][en-1]='R';
                k-=2;
                en+=2;
            }
            en-=2;
            num++;
            int enl=1;
            if(n%2)
            {
                while(k>1&&enl<n)
                {
                    mp[enl-1][n-1]='D';
                    mp[enl][n-1]='U';
                    k-=2;
                    enl+=2;
                }
                if(enl>=n) enl-=2;
            }
            if(enl==1) enl=0;
            //cout<<"en:"<<en<<" k:"<<k<<endl;
            int my=0;
            for(int i=1;i<n&&k>0;i++) for(int j=en;k>0&&j>=0;j--)
            {
                //cout<<114514<<endl;
                mp[i][j]='U';
                k--;
                my=max(i,my);
                // cout<<k<<endl;
                // cout<<i<<' '<<j<<" "<<mp[i][j]<<endl;
            }
            //cout<<my<<' '<<enl<<endl;
            if(en+1!=n-n%2) for(int i=en+1;i<n;i++) mp[1][i]='R';
            if(n%2) for(int i=enl+1;i<=my;i++)  mp[i][n-1]='R';
        }
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++) 
        {
            for(int j=0;j<n;j++) cout<<mp[i][j];
            cout<<endl;
        }
    }
    return 0;
}
/*
大师方案
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        // 特殊情况：k = n^2 - 1 无法构造
        if (k == n * n - 1) {
            cout << "NO" << endl;
            continue;
        }
        
        vector<vector<char>> grid(n, vector<char>(n, 'U'));
        
        // 先让所有点都指向边界（向上）
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = 'U';
            }
        }
        
        // 现在所有点都能逃脱，我们需要减少逃脱点的数量
        int reduce = n * n - k;
        
        // 如果reduce是0，直接输出
        if (reduce == 0) {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << grid[i][j];
                }
                cout << endl;
            }
            continue;
        }
        
        // 从最后一行开始，创建循环来减少逃脱点
        bool possible = true;
        for (int i = n - 1; i >= 0 && reduce > 0; i--) {
            for (int j = n - 1; j >= 0 && reduce > 0; j--) {
                // 跳过第一列，因为可能会影响其他逃脱点
                if (j == 0) continue;
                
                // 创建水平循环
                if (reduce >= 2) {
                    grid[i][j] = 'L';
                    grid[i][j-1] = 'R';
                    reduce -= 2;
                    j--; // 跳过下一个位置
                } else if (reduce == 1) {
                    // 只减少1个逃脱点：让这个点指向一个已经不能逃脱的点
                    // 我们可以让这个点指向右边，而右边是一个已经设置为L的点
                    if (j < n - 1 && grid[i][j+1] == 'L') {
                        grid[i][j] = 'R';
                        reduce -= 1;
                    } else if (i > 0 && grid[i-1][j] == 'U') {
                        // 或者让这个点指向下面，而下面是一个已经设置为U的点
                        grid[i][j] = 'D';
                        reduce -= 1;
                    } else {
                        // 如果无法减少1个，说明无法构造
                        possible = false;
                    }
                }
            }
        }
        
        if (!possible || reduce > 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << grid[i][j];
                }
                cout << endl;
            }
        }
    }
    
    return 0;
}
*/