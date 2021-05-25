n,m=map(int,input().split())
L=[[] for _ in range(n+1)]
v=[0]*(n+1)
c=0
for _ in range(m):
    a,b=map(int,input().split())
    L[a].append(b)
    L[b].append(a)
for i in range(1,n+1):
    if v[i]==1:
        continue
    v[i]=1
    stack=[i]
    while len(stack)>0:
        k=stack.pop()
        for j in L[k]:
            if v[j]==0:
                v[j]=1
                stack.append(j)
    c+=1
print(c)