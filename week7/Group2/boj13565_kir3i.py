import sys
from collections import deque
input = sys.stdin.readline

def init(r, c):
    return [list(map(int, input().strip())) for _ in range(r)]

def is_on_board(x, y, r, c):
    return 0 <= x < c and 0 <= y < r

def bfs(board, start, vst):
    r, c = len(board), len(board[0])
    vst.add(start)
    q = deque([start])

    while q:
        x, y = q.popleft()
        if y == r-1:
            return True
        for dx, dy in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
            nx, ny = x+dx, y+dy
            if is_on_board(nx, ny, r, c) and board[ny][nx] == 0 and (nx, ny) not in vst:
                q.append((nx, ny))
                vst.add((nx, ny))
    return False

if __name__ == '__main__':
    r, c = map(int, input().strip().split())
    board = init(r, c)
    vst = set()
    ok = False
    for x in range(c):
        if board[0][x] == 0 and (x, 0) not in vst:
            ok |= bfs(board, (x, 0), vst)
            if ok:
                break
    print('YES' if ok else 'NO')
