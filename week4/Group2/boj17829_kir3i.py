import sys
input = sys.stdin.readline

def solv(N, mat, x, y):
    if N == 1:
        return mat[y][x]
    return sorted([solv(N//2, mat, x+dx, y+dy) for dx, dy in [(0, 0), (N//2, 0), (0, N//2), (N//2, N//2)]])[-2]

if __name__ == '__main__':
    N = int(input().strip())
    mat = [list(map(int, input().strip().split())) for _ in range(N)]
    print(solv(N, mat, 0, 0))
