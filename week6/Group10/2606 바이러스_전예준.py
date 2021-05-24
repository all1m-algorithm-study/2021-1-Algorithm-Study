n=int(input())
L=[[] for _ in range(n+1)]
for _ in range(int(input())):
    a,b=map(int,input().split())
    L[a].append(b)
    L[b].append(a)
c=-1
stack=[1]
visited=[1]
while len(stack)>0:
    p=stack.pop()
    c+=1
    for i in L[p]:
        if i in visited:
            continue
        else:
            stack.append(i)
            visited.append(i)
print(c)