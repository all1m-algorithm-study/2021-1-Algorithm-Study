import sys
h,w=map(int,input().split())
L=[]
for _ in range(h):
    L.append([int(i) for i in sys.stdin.readline().rstrip()])
dx=[-1,0,1,0]
dy=[0,1,0,-1]
v=[[0]*w for _ in range(h)]
answer=False
for i in range(w):
    if L[0][i]==0 and v[0][i]==0:
        stack=[(0,i)]
        while len(stack)>0:
            x,y=stack.pop()
            if x==h-1:
                answer=True
            v[x][y]=1
            for j in range(4):
                nx,ny=x+dx[j],y+dy[j]
                if 0<=nx<=h-1 and 0<=ny<=w-1 and v[nx][ny]==0 and L[nx][ny]==0:
                    stack.append((nx,ny))
if answer:
    print('YES')
else:
    print('NO')