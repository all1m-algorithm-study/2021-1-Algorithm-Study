import sys
input = sys.stdin.readline
sys.setrecursionlimit(30000)

board = []

def chk(N, x, y):
    standard = board[y][x]
    for dy in range(N):
        for dx in range(N):
            if board[y+dy][x+dx] != standard:
                return False
    return True

def solv(N, x, y):
    rtn = [0, 0, 0]
    if N == 1:
        rtn[board[y][x]] += 1
        return rtn


    if chk(N, x, y):
        rtn[board[y][x]] += 1
    else:
        dx, dy = N // 3, N // 3
        for nx, ny in [(x, y), (x+dx, y), (x+2*dx, y),
                       (x, y+dy), (x+dx, y+dy), (x+2*dx, y+dy),
                       (x, y+2*dy), (x+dx, y+2*dy), (x+2*dx, y+2*dy)]:
            a = solv(N//3, nx, ny)
            rtn[0] += a[0]
            rtn[1] += a[1]
            rtn[2] += a[2]
    return rtn

if __name__ == '__main__':
    N = int(input().strip())
    for _ in range(N):
        board.append(list(map(int, input().strip().split())))
    ans = solv(N, 0, 0)
    for i in range(-1, 2):
        print(ans[i])

