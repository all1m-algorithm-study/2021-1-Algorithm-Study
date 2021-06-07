import sys

input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

num = int(input())
tree = [[] for _ in range(num + 1)]
table = {}
check = [False] * (num + 1)

def dfs(v):
    check[v] = True
    for i in tree[v]:
        if not check[i]:
            # print(i)
            table[i] = v
            dfs(i)

for _ in range(num - 1):
    a, b = map(int, input().split())
    tree[a].append(b)
    tree[b].append(a)
# print(tree)

dfs(1)
# print(table)

# 출력
for i in range(2, num + 1):
    if i in table:
        print(table[i])
    # else:
    #     break