import sys

n = int(sys.stdin.readline())
matrix = []
for i in range(0, n):
    matrix += list(map(int, sys.stdin.readline().split()))

def pulling(matrix, i, x, y):
    if(i == 1): return matrix[y * n + x]
    sub = []

    m = i // 2
    sub.append(pulling(matrix, m, x, y))
    sub.append(pulling(matrix, m, x + m, y))
    sub.append(pulling(matrix, m, x, y + m))
    sub.append(pulling(matrix, m, x + m, y + m))
    sub.sort()

    return sub[-2]
    
    # for i in range(0, n//2):
    #     for j in range(0, n // 2):
    #         dy = [i * 2, i * 2 + 1]
    #         dx = [j * 2, j * 2 + 1]
    #         second = []
    #         for k in range(0, 2):
    #             for l in range(0, 2):
    #                 second.append(matrix[dy[k] * n + dx[l]])
    #         second.sort()
    #         sub.append(second[-2])
    #         j += 2
    #     i += 2
    # return pulling(sub, n // 2)

print(pulling(matrix, n, 0, 0))