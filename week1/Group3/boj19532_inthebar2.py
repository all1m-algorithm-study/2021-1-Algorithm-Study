a, b, c, d, e, f = map(int, input().split(' '))

found = 0
for x in range(-999, 1000):
    for y in range(-999, 1000):
        if a * x + b * y == c and d * x + e * y == f:
            print(x, y)
            found = 1
            break
    if found:
        break
