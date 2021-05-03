def check(l):
    c = l[0]
    for i in l:
        if(i != c): return -2
    return c

def cut(l, n):
    c = check(l) + 1
    if(c >= 0):
        count[c] += 1
    else:
        n = n // 3
        for i in range(0, 9):
            tmp = []
            for j in range(0, n):
                k = (i % 3) * n + (i // 3) * n * n * 3 + j * n * 3
                tmp += l[k : k + n]
            cut(tmp, n)

n = int(input())
l = []
count = [0, 0, 0]

for i in range(0, n):
    l += list(map(int, input().split()))

cut(l, n)
print('\n'.join(map(str, count)))