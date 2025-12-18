t=int(input())
for _ in range(t):
    n,m=map(int,input().split())
    s=input()
    lb=[0]*n;bc=[0]*n
    if s[0]=='1':
        lb[0]=-1
    if s[n-1]=='1':
        bc[n-1]=n-1
    else:
        bc[n-1]=n
    for i in range(1,n):
        lb[i]=lb[i-1]
        if s[i]=='0':
            lb[i]=i
    for i in range(n-2,-1,-1):
        bc[i]=bc[i+1]
        if s[i]=='1':
            bc[i]=i
    ans=[]
    for __ in range(m):
        l,r=map(int,input().split())
        l-=1;r-=1
        if bc[l]>=lb[r]:
            ans.append(-1)
        else: 
            ans.append(bc[l]*2000000+lb[r])
    ans=list(set(ans))
    print(len(ans))
