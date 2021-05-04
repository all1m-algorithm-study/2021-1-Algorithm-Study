N = list(map(int, input().split()))
a, b, c, d, e, f = N[0], N[1], N[2], N[3], N[4], N[5]

resultFlag = False
x, y = None, None

for x in range(-999, 1000):
    for y in range(-999, 1000):
        if (a*x+b*y == c) and (d*x+e*y == f):
            resultFlag = True
            break
    if resultFlag == True:
        break

print("%d %d" % (x, y))
