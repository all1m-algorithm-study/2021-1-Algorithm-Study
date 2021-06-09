import sys
from collections import deque

input = sys.stdin.readline

que = deque()
answer = []

A, B, C = map(int, input().split())

# A, B가 가질 수 있는 물의 양의 경우의 수
visited = [[0] * (B + 1) for _ in range(A + 1)] # 행(A)렬(B)

# print(visited)

# A와 B 사이에서 물을 붓는 경우
def pour(a, b):
    if visited[a][b] == 0:
        que.append((a, b))
        visited[a][b] = 1

def bfs():
    que.append((0,0))  # 처음 물통 A, B 물 양은 0, 0
    visited[0][0] = 1  

    # que 안에 (a, b) 경우의 수가 있을 때까지 반복
    while que:
        a, b = que.popleft()
        c = C - (a + b) # C의 물양
        # a가 0이란 것은 A 물통에 물이 없는 경우이므로 이 때 C의 물의 양인 c를 저장
        if a == 0:
            answer.append(c)
        
        # A, B, C의 물통의 물이 이동할 수 있는 경우의 수는 총 6개
        # 1. A -> C
        if a > 0 and c < C:
            # water는 이동할 수 있는 물의 양
            water = min(a, C - c)   # a의 물의 양과 C가 현재 가질 수 있는 물의 양 중 더 작은 물의 양을 이동시킨다. 물통을 초과할 수 있기 때문에
            pour(a - water, b)      # 이동할만큼의 물의 양을 A에서 빼고 B는 가만히 있는다

        # 2. A -> B
        if a > 0 and b < B:
            water = min(a, B - b)
            pour(a - water, b + water)
        
        # 3. B -> C
        if b > 0 and c < C:
            water = min(b, C - c)
            pour(a, b - water)
        
        # 4. B -> A
        if b > 0 and a < A:
            water = min(b, A - a)
            pour(a + water, b - water)
        
        # 5. C -> A
        if c > 0 and a < A:
            water = min(c, A - a)
            pour(a + water, b)
        
        # 6. C -> B
        if c > 0 and b < B:
            water = min(c, B - b)
            pour(a, b + water)

# 처음 A, B의 물의 양이 0일 때 부터 시작
bfs()
answer.sort()
print(' '.join(list(map(str, answer))))

        



