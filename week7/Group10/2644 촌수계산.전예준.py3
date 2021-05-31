import sys
n=int(input())
L=[[] for _ in range(n+1)]
v=[0]*(n+1)
a,b=map(int,input().split())
m=int(input())
for _ in range(m):
    p,q=map(int,sys.stdin.readline().split())
    L[p].append(q)
    L[q].append(p)
result=-1
def DFS(m,n,k):
    global result
    v[m]=1
    for i in L[m]:
        if i==n:
            result=k+1
            return
        if v[i]==0:
            DFS(i,n,k+1)
    return
DFS(a,b,0)
print(result)