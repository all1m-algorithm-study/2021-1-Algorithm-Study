import sys
sys.setrecursionlimit(10000)

input = sys.stdin.readline

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

num = int(input())

map_list = [list(map(int, input().split())) for _ in range(num)]

# print(map_list)

def dfs(x, y, water_level):
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if (0 <= nx < num) and (0 <= ny < num) and (map_list[nx][ny] > water_level) and not visited[nx][ny]:
            visited[nx][ny] = True
            dfs(nx, ny, water_level)

ans = 1
for water_level in range(1, 101):
    count = 0
    visited = [[False] * num for _ in range(num)]
    for i in range(num):
        for j in range(num):
            if map_list[i][j] > water_level and not visited[i][j]:
                visited[i][j] = True
                # 안전지대
                count += 1
                dfs(i, j, water_level)
    # 배열의 모든 원소를 비교를 끝낸 후 안전지대 최댓값 비교
    ans = max(ans, count)

print(ans)
                 
    