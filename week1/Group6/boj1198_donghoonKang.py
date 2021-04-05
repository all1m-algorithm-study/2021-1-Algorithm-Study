N = int(input())

x = []
y = []
for i in range(0, N):
    temp = list(map(int, input().split()))
    x.append(temp[0])
    y.append(temp[1])


def getArea(a, b, c, d, e, f):
    return (1/2)*abs((a*d+c*f+e*b)-(c*b+e*d+a*f))


maxArea = 0
tmp = 0

for a in range(0, N):
    for b in range(0, N):
        for c in range(0, N):
            tmp = getArea(x[a], y[a], x[b], y[b], x[c], y[c])
            if tmp > maxArea:
                maxArea = tmp

print(maxArea)

"""
N = int(input())

x = []
y = []
for i in range(0, N):
    temp = list(map(int, input().split()))
    x.append(temp[0])
    y.append(temp[1])


def getArea(a, b, c, d, e, f):
    return (1/2)*abs((a*d+c*f+e*b)-(c*b+e*d+a*f))


maxArea = 0
tmp = 0

for j in range(0, N):
    for k in range(1, N-1):
        a = (j+k) % N
        b = (j+k+1) % N
        tmp = getArea(x[j], y[j], x[a], y[a], x[b], y[b])
        if tmp > maxArea:
            maxArea = tmp

print(maxArea)
"""
