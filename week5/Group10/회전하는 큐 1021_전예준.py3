from collections import deque
n,m=map(int,input().split())
Q=deque(list(range(1,n+1)))
L=list(map(int,input().split()))
total=0
for i in L:
    if Q.index(i) < len(Q)-Q.index(i):
        total+=Q.index(i)
        Q.rotate(-Q.index(i))
        Q.popleft()
    else:
        total+=len(Q)-Q.index(i)
        Q.rotate(len(Q)-Q.index(i))
        Q.popleft()
print(total)