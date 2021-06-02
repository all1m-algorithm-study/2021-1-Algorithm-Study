import sys
sys.setrecursionlimit(1000000)

def DFS(square_map, y, x):
    square_map[y][x] = 0
    for ny, nx in direction:
        Y = y + ny
        X = x + nx
        if (0 <= Y < b) and (0 <= X < a) and (square_map[Y][X] == 1):
            DFS(square_map, Y, X)
            
direction = [[1, 0], [-1, 0], [0, 1], [0, -1], [1, 1], [-1, -1], [-1, 1], [1, -1]]

while True:
    a, b = map(int, input().split())
    if a == 0 and b == 0:
        break
        
    square_map = [list(map(int, input().split())) for _ in range(b)]
        
    cnt = 0
    for x in range(a):
        for y in range(b):
            if square_map[y][x] == 1:
                DFS(square_map, y, x)
                cnt += 1
    print(cnt)
