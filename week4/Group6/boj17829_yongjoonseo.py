# 반씩 쪼개어서 크기가 4일 때만 2번째로 큰 원소 반환
    # 길이가 2


import sys
input = sys.stdin.readline

def pooling(field, y, x, n):
    if n == 2:
        lst = [field[y][x], field[y+1][x], field[y][x+1], field[y+1][x+1]]
    else:
        lst = []
        lst.append(pooling(field, y, x, n//2))
        lst.append(pooling(field, y + n//2, x, n//2))
        lst.append(pooling(field, y, x + n//2, n//2))
        lst.append(pooling(field, y + n//2, x + n//2, n//2))
    lst.sort()
    return lst[-2]

def solution(N):
    field = [list(map(int, input().split())) for _ in range(N)]
    print(pooling(field, 0, 0, N))

if __name__ == '__main__':
    solution(int(input()))