// #include<bits/stdc++.h>
// #define int long long
// using namespace std;
// int pows[101],nums[1000001],sums[1010010],k;
// int check(int x)
// {
//     int len=log10(x);
//     int sum=0;
//     for(int i=1;i<=len;i++) sum+=i*9*pows[i];
//     sum+=(x-pows[len]+1)*len;
//     return sum
// }
// signed main()
// {
//     pows[0]=1;
//     // int len=0;
//     for(int i=1;i<=18;i++) pows[i]=10*pows[i-1];
//     // for(int i=1;nums[i-1]<LONG_LONG_MAX/100&&i<1000000;i++) nums[i]=nums[i-1]+log10(i)+1,len=i;
//     // for(int i=1;sums[i-1]<LONG_LONG_MAX/100&&i<=len;) 
//     // {
//     //     int x=i;
//     //     int lenx=log10(x);
//     //     sums[i]=sums[i-1];
//     //     while(x)
//     //     {
//     //         sums[i]+=x%10;
//     //         x/=10;
//     //     }
//     //     i+=1;
//     // }
//     // for(int i=1;i<=20;i++) cout<<nums[i]<<' ';
//     // cout<<endl;
//     // for(int i=1;i<=20;i++) cout<<sums[i]<<' ';
//     // cout<<endl;
//     // int t;
//     // cin>>t;
//     // while(t--)
//     // {
//     //     int k;
//     //     cin>>k;
//     //     int id=lower_bound(nums+1,nums+len+1,k)-nums;
//     //     id--;
//     //     int ans=sums[id];
//     //     int cnt=k-id;
//     //     int x=id+1;
//     //     int lenx=log10(x)+1;
//     //     cout<<"id "<<id<<endl;
//     //     cout<<"num "<<nums[id]<<endl;
//     //     while(lenx)
//     //     {
//     //         if(lenx<=cnt) ans+=x%10;
//     //         x/=10;
//     //         lenx--;
//     //     }
//     //     cout<<ans<<endl;
//     // }
//     // return 0;
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         cin>>k;
//         int l=1,r=k;
//         int id;
//         while(l<=r)
//         {
//             int mid=l+r>>1;
//             if(check(mid)<=k) id=mid,l=mid+1;
//             else r=mid-1;
//         }
//         int x=id+1;
//         int len=log10(x);
//         int cnt=k-check(id);
//         int ans=0;
//         while(len)
//         {
//             if(len<=cnt) ans+=x%10;
//             x/=10;
//             len--;
//         }
        
//     }
// }