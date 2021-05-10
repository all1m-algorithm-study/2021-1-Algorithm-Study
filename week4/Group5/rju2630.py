n = int(input())
count = [0, 0]
matrix = []
for i in range(0, n):
    matrix.append(list(map(int, input().split())))

def cut(i, x, y):
    global matrix
    if(i == 1): return matrix[y][x]

    m = i // 2

    p1 = cut(m, x, y)
    p2 = cut(m, x + m, y)
    p3 = cut(m, x, y + m)
    p4 = cut(m, x + m, y + m)

    if(p1 >= 0 and p1 == p2 and p1 == p3 and p1 == p4):
        return p1
    else:
        if(p1 >= 0): count[p1] += 1
        if(p2 >= 0): count[p2] += 1
        if(p3 >= 0): count[p3] += 1
        if(p4 >= 0): count[p4] += 1
        return -1

p = cut(n, 0, 0)
if(p >= 0):
    count[p] += 1
print(count[0], count[1])