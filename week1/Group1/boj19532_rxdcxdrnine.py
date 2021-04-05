enter = input()
a, b, c, d, e, f = list(map(int, enter.split()))


def equation(a, b, c, d, e, f):
    for x in range(-999, 1000):
        for y in range(-999, 1000):
            if a * x + b * y == c and d * x + e * y == f:
                return x, y


result = equation(a, b, c, d, e, f)
print(' '.join(map(str, result)))