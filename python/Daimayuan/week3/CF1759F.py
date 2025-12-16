import bisect
t=int(input())
for _ in range(t):
    n,p=map(int,input().split())
    a=list(map(int,input().split()))
    a=[0]+a
    alm=[]
    for i in range(1,n+1):
        alm.append(a[i])
    alm=sorted(set(alm))
    if len(alm)==p:
        print(0)
        continue
    ans=0
    pos=bisect.bisect_left(alm,a[n])
    while 1:
        ans+=1
        if alm[(pos-1)%len(alm)]%p!=(alm[pos%len(alm)]-1)%p: 
            break
        pos-=1
    ans=p-ans
    if a[n]!=0:
        ansl=0
        ed=1
        pos=n-1
        while pos>=1 and a[pos]==p-1:
            pos-=1
        if pos>=1:
            ed=a[pos]+1
        else:
            ed=1
        pos=bisect.bisect_left(alm,ed)
        if pos==len(alm) or alm[pos]!=ed:
            alm.insert(pos,ed)
        pos=bisect.bisect_left(alm,0)
        if pos==len(alm) or alm[pos]!=0:
            alm.insert(pos,0)
        pos=bisect.bisect_left(alm,a[n])
        if len(alm)==p:
            ans=min(ans,p-a[n])
        else:
            while 1:
                ansl+=1
                if alm[(pos-1)%len(alm)]%p!=(alm[pos%len(alm)]-1)%p: 
                    break
                pos-=1
            ans=min(ans,max(p-ansl,p-a[n]))
    print(ans)
