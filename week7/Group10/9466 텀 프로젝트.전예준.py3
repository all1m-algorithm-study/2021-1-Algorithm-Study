import sys
for _ in range(int(sys.stdin.readline().rstrip())):
    n = int(sys.stdin.readline().rstrip())
    L = [0]
    L += [*map(int, sys.stdin.readline().split())]
    answer = n
    visited=[0]*(n+1)
    for i in range(1, n + 1):
        isinstack=[]
        p=i
        while visited[p]==0:
            isinstack.append(p)
            visited[p]=1
            p=L[p]
        if L[p] in isinstack:
            while visited[p]!=2:
                visited[p]=2
                p=L[p]
                answer-=1
    print(answer)