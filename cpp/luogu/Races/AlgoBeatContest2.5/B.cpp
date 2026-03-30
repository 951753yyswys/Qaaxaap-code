#include <bits/stdc++.h>
#define int __int128
using namespace std;
struct cake
{
    int d,x,c;
} a[101011];
// 读入 __int128 的函数，会返回读入的数。
__int128 read() {
    char c;
    bool isf = 0;
    while (!isdigit(c = getchar())) {
    	isf = (c == '-');
    }
    __int128 res = (c ^ 48);
    while (isdigit(c = getchar())) {
    	res = (res << 3) + (res << 1) + (c ^ 48);
    }
    return isf ? -res : res;
}

// 输出 __int128 的函数。需传入需要输出的数作为参数。
void write(__int128 x) {
    if (x < 0) {
    	putchar('-'), x = -x;
    } 
    if (x >= 10) {
    	write(x / 10);
    }
    putchar('0' + x % 10);
}
bool cmp(cake x,cake y)
{
    return x.x>y.x;
}
signed main() {
    int n=read(),ans=0;
    for(int i=1;i<=n;i++) 
    {
        a[i].c=read();
        a[i].d=read();
        a[i].x=read();
        ans+=a[i].c*a[i].d+a[i].c*a[i].x;
    }
    sort(a+1,a+n+1,cmp);
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        ans-=a[i].c*sum*a[i].x;
        ans-=a[i].x*a[i].c*(a[i].c+1)/2;
        sum+=a[i].c;
    }
    write(ans);
	return 0;
}
