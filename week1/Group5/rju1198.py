def area(p1, p2, p3):
    return abs(p1[0] * p2[1] + p2[0] * p3[1] + p3[0] * p1[1] - p1[1] * p2[0] - p2[1] * p3[0] - p3[1] * p1[0]) / 2

n = int(input())
p = [0] * n
for i in range(0, n):
    p[i] = list(map(int, input().split()))

result = 0
for i in range(0, n - 2):
    for j in range(i + 1, n - 1):
        for k in range(j + 1, n):
            result = max(area(p[i], p[j], p[k]), result)


print(result)