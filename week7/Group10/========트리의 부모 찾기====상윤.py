========트리의 부모 찾기====

def dfs(x):
    q = [x]
    visited = [0 for i in range(n+1)]
    visited[1] = 1

    while q:
        now = q.pop(0)
        
        for nxt in adj[now]:
            if visited[nxt] == 0:
                q.append(nxt)
                ans[nxt] = now
                visited[nxt] = 1
        


import sys
n  = int(sys.stdin.readline())

adj = [[]for i in range(n+1)]

for i in range(n-1):
    a, b = map(int,sys.stdin.readline().split())

    adj[a].append(b)
    adj[b].append(a)

ans = [0 for i in range(n+1)]

dfs(1)

for i in range(2,n+1):
    print(ans[i])

