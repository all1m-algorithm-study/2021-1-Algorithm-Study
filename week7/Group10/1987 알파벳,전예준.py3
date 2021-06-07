import sys
input = sys.stdin.readline
h,w=map(int,input().split())
visited=[False]*26
L=[]
for _ in range(h):
    L.append(input().rstrip())
result=1
def DFS(x,y,c):
    global result
    K=ord(L[x][y])
    visited[K-65]=True
    for p,q in ((x-1,y),(x,y+1),(x+1,y),(x,y-1)):
        if 0<=p<=h-1 and 0<=q<=w-1:
            k=ord(L[p][q])
            if visited[k-65]==False:
                DFS(p,q,c+1)
                visited[k-65]=False
    else:
        if c>result:
            result=c
DFS(0,0,1)
print(result)