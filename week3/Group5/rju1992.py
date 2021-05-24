def quadTree(data, n, x, y):
    c = check(data, n, x, y)

    if(c != ""):
        return c
    else:
        s = "("
        n = n // 2
        s += quadTree(data, n, x, y)
        s += quadTree(data, n, x + n, y)
        s += quadTree(data, n, x, y + n)
        s += quadTree(data, n, x + n, y + n)
        s += ")"
        return s

def check(data, n, x, y):
    d = data[y][x]
    for i in range(y, y + n):
        for j in range(x, x + n):
            if(d != data[i][j]): return ""
    return d

n = int(input())
data = []

for i in range(0, n):
    data.append(input())

print(quadTree(data, n, 0, 0))