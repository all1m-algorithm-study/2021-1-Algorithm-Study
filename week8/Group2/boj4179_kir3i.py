import sys
from collections import deque
input = sys.stdin.readline

def init(r, c):
    board = [[0] * c for _ in range(r)]
    fire = deque()
    start = None
    for y in range(r):
        line = input().strip()
        for x in range(c):
            if line[x] == '.':
                board[y][x] = 1
            if line[x] == 'J':
                start = (x, y)
                board[y][x] = 1
            if line[x] == 'F':
                fire.append((x, y))
                board[y][x] = 0
    return board, start, fire

def on_board(x, y, r, c):
    return 0 <= x < c and 0 <= y < r

def update_fire(board, vst, fire):
    q = deque()
    r, c = len(board), len(board[0])
    while fire:
        x, y = fire.popleft()
        for dx, dy in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
            nx, ny = x+dx, y+dy
            if on_board(nx, ny, r, c) and (nx, ny) not in vst and board[ny][nx] == 1:
                q.append((nx, ny))
                vst.add((nx, ny))
                board[ny][nx] = 0
    return q

def bfs(board, vst, start, fire):
    q = deque([start])
    r, c = len(board), len(board[0])
    vst.add(start)
    fire_chk = set(fire)
    lv = 1
    while q:
        qsz = len(q)
        fire = update_fire(board, fire_chk, fire)
        for _ in range(qsz):
            x, y = q.popleft()
            if y in [0, r-1] or x in [0, c-1]:
                return lv
            for dx, dy in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
                nx, ny = x+dx, y+dy
                if on_board(nx, ny, r, c) and (nx, ny) not in vst and board[ny][nx] == 1:
                    q.append((nx, ny))
                    vst.add((nx, ny))

        lv += 1
    return 'IMPOSSIBLE'

if __name__ == '__main__':
    r, c = map(int, input().strip().split())
    board, start, fire = init(r, c)
    print(bfs(board, set(), start, fire))
