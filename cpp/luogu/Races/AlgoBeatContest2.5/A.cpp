#include<bits/stdc++.h>
#define int __int128
using namespace std;
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

signed main()
{
    int n,m;
    int T;
    T=read();
    while(T--)
    {
        n=read();
        m=read();
        if(m<n*(n+1)/2) write(-1),printf(" "),write(-1),printf("\n");
        else {write(n+m-n*(n+1)/2-1);
            printf(" ");
        write(bool((m-n*(n+1)/2)%n)+n-1);
    printf("\n");}
    }
    return 0;
}