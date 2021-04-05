a, b, c, d, e, f = map(int, input().split())

x = 0
y = 0
for i in range(-999, 1000):
    for j in range(-999, 1000):
        if a*i+b*j==c and d*i+e*j==f:
            x = i; y = j
print(x, y)