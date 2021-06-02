import sys
n=int(input())
L=[]
for _ in range(n):
    L.append(list(map(int,sys.stdin.readline().split())))
dx=[-1,0,1,0]
dy=[0,1,0,-1]
v=[[0 for _ in range(n)] for _ in range(n)]
def flood(k,u):
    for x in range(n):
        for y in range(n):
            if L[x][y]>k and v[x][y]==0:
                stack=[[x,y]]
                while len(stack)>0:
                    p,q=stack.pop()
                    v[p][q]=1
                    for i in range(4):
                        nx,ny=p+dx[i],q+dy[i]
                        if 0<=nx<=(n-1) and 0<=ny<=(n-1) and L[nx][ny]>k and v[nx][ny]==0:
                            stack.append([nx,ny])
                return flood(k,u+1)
    return u
i,m=0,0
p=flood(i,0)
while p>0:
    v = [[0 for _ in range(n)] for _ in range(n)]
    if p>m:
        m=p
    i+=1
    p=flood(i,0)
print(m)