import math
import sys
input=lambda:sys.stdin.readline().strip()
t=int(input())
for _ in range(t):
    x,z=map(int,input().split())
    if z%x:
        print(-1)
        continue
    d=math.gcd(int(z/x),x*x)
    sqr=int(math.sqrt(d))
    if sqr*sqr!=d: 
        print(-1)
        continue
    print(int(z/x/sqr))
