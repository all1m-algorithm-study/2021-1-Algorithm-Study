import sys
from collections import deque
input = sys.stdin.readline

def init(w, h):
    return [list(map(int, input().strip().split())) for _ in range(h)]

def is_on_board(x, y, w, h):
    return 0 <= x < w and 0 <= y < h

def bfs(board, start, vst):
    w, h = len(board[0]), len(board)
    vst.add(start)
    q = deque([start])

    while q:
        x, y = q.popleft()
        for dx, dy in [(1, 0), (0, 1), (-1, 0), (0, -1), (1, -1), (-1, 1), (1, 1), (-1, -1)]:
            nx, ny = x+dx, y+dy
            if is_on_board(nx, ny, w, h) and \
                    (nx, ny) not in vst and board[y][x] == 1:
                q.append((nx, ny))
                vst.add((nx, ny))



if __name__ == '__main__':

    while True:
        w, h = map(int, input().strip().split())
        if w == 0 and h == 0:
            break

        board = init(w, h)
        vst = set()
        cnt = 0
        for y in range(h):
            for x in range(w):
                if board[y][x] == 1 and (x, y) not in vst:
                    bfs(board, (x, y), vst)
                    cnt += 1

        print(cnt)
