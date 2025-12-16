t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    spl=[0]*(n+2);
    a=[0]+a
    b=[0]+b
    ans=[]
    for i in range(1,n+1):
        if a[i]>b[i]:
            spl[b[i]]=spl[b[i]]+1
            spl[a[i]]=spl[a[i]]-1
    for i in range(1,n+1):
        spl[i]+=spl[i-1]
    for i in range(1,n+1):
        flag=1
        for j in range(i,n+1,i):
            if spl[j]:
                flag=0
        if flag:
            ans.append(i)
    print(len(ans))
    for i in range(0,len(ans)):
        print(ans[i],end=' ')
    print()
