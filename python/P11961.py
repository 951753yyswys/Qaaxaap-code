import math
def qp(d,z,mod):
    t=1
    while z:
        if z&1:
            t*=d
            t%=mod
        d*=d
        d%=mod
        z>>=1
    return t
t=int(input())
for _ in range(t):
    a,mod=map(int,input().split())
    flag=1
    for i in range(2,int(math.sqrt(mod-1))+1):
        if (mod-1)%i==0:
            if qp(a,i,mod)==1 or qp(a,int((mod-1)/i),mod)==1:
                flag=0
            if flag==0:
                break;
    if flag:
        print("Yes")
    else:
        print("No")
