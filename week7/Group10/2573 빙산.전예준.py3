import sys
input = sys.stdin.readline
sys.setrecursionlimit(90000)
n,m=map(int,input().split())
L=[]
for _ in range(n):
    L.append([*map(int,input().split())])
year=0
visited=[[0]*m for _ in range(n)]
def melt(X,Y):
    forecast=4
    visited[X][Y]=1
    for x,y in ((X-1,Y),(X,Y+1),(X+1,Y),(X,Y-1)):
        if 0<=x<n and 0<=y<m and L[x][y]!=0:
            forecast-=1
    for x,y in ((X-1,Y),(X,Y+1),(X+1,Y),(X,Y-1)):
        if 0<=x<n and 0<=y<m and L[x][y]!=0 and visited[x][y]==0:
            melt(x,y)
    L[X][Y]=max(L[X][Y]-forecast,0)
    return
while 1:
    isitallzero=True
    count = 0
    for i in range(n):
        for j in range(m):
            if visited[i][j]==1 or L[i][j]==0:
                continue
            else:
                isitallzero=False
                melt(i,j)
                count+=1
    if isitallzero or count>1:
        break
    else:
        year+=1
        visited = [[0] * m for _ in range(n)]
if isitallzero:
    print(0)
else:
    print(year)