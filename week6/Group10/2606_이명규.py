N = int(input())
E = int(input())
adj = [[] for _ in range(N)]
for _ in range(E):
    a, b = map(int, input().split())
    adj[a - 1].append(b - 1)
    adj[b - 1].append(a - 1)
# [[1, 4], [0, 2, 4], [1], [6], [0, 1, 5], [4], [3]]


# dfs: https://security-nanglam.tistory.com/413
def recursive_dfs(v, discovered=[]):
    discovered.append(v)  # discovered는 탐색한 노드들을 저장한다.
    for w in adj[v]:
        if not w in discovered:  # w가 탐색한 노드가 아니라면 탐색한다.
            discovered = recursive_dfs(w, discovered)
    return discovered


print(len(recursive_dfs(0)) - 1)
