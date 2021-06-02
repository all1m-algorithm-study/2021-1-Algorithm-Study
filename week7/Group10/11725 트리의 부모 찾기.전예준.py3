n=int(input())
D={1:1}
L=[[] for _ in range(n+1)]
for _ in range(n-1):
    a,b=map(int,input().split())
    L[a].append(b)
    L[b].append(a)
stack=[1]
visited=[0]*(n+1)
while len(stack)>0:
    p=stack.pop()
    visited[p]=1
    for i in L[p]:
        if visited[i]==0:
            D[i] = p
            stack.append(i)
for i in range(2,n+1):
    print(D[i])