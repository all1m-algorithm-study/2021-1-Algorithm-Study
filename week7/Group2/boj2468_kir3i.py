import sys
from collections import deque
input = sys.stdin.readline

def init(N):
    return [list(map(int, input().strip().split())) for _ in range(N)]

def on_board(x, y, n):
    return 0 <= x < n and 0 <= y < n

def bfs(board, start, vst, water_height):
    n = len(board)
    vst.add(start)
    q = deque([start])

    while q:
        x, y = q.popleft()
        for dx, dy in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
            nx, ny = x+dx, y+dy
            if on_board(nx, ny, n) and board[ny][nx] > water_height and (nx, ny) not in vst:
                q.append((nx, ny))
                vst.add((nx, ny))

if __name__ == '__main__':
    N = int(input().strip())
    board = init(N)
    ans = 0

    for h in range(101):
        vst = set()
        cnt = 0
        for y in range(N):
            for x in range(N):
                if board[y][x] > h and (x, y) not in vst:
                    bfs(board, (x, y), vst, h)
                    cnt += 1
        if cnt == 0:
            break   # 모든 영역이 물에 잠겼다!
        ans = max(ans, cnt)

    print(ans)
