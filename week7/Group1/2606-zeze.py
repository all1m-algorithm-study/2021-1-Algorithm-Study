com_num = int(input())
network_num = int(input())

computer = {}
visited = []

for i in range(1, com_num+1):
    computer[i] = set()

for j in range(1, network_num+1):
    one, two = map(int, input().split())
    computer[one].add(two)
    computer[two].add(one)


def dfs(key, computer):
    for i in computer[key]:
        if i not in visited:
            visited.append(i)
            dfs(i, computer)


dfs(1, computer)
print(len(visited)-1)  # visted에 1이 제일 먼저 들어감으로
