import itertools
n,m=map(int,input().split())
L=list(itertools.combinations(range(1,n+1),m))
for i in range(len(L)):
    print(*L[i])