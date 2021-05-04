tri = []
for i in range(1, 46):
    tri.append(int(i * (i + 1) / 2))


def possible(n):
    for a in tri:
        for b in tri:
            for c in tri:
                if a + b + c == n:
                    return 1
    return 0


N = int(input())

for i in range(N):
    print(possible(int(input())))

1198번:
N = int(input())
cord = list()

for i in range(N):
    cord.append(list(map(int, input().split())))

max_area = abs(cord[0][0]*cord[1][1]+cord[1][0]*cord[2][1]+cord[2][0]*cord[0][1]-cord[1][0]*cord[0][1]-cord[2][0]*cord[1][1]-cord[0][0]*cord[2][1]) / 2

for a in cord:
    for b in cord:
        for c in cord:
            if max_area < abs(a[0]*b[1]+b[0]*c[1]+c[0]*a[1]-b[0]*a[1]-c[0]*b[1]-a[0]*c[1]) / 2:
                max_area = abs(a[0]*b[1]+b[0]*c[1]+c[0]*a[1]-b[0]*a[1]-c[0]*b[1]-a[0]*c[1]) / 2

print(max_area)

1254번:
x = list(input())
num = 0
while not x + x[:num][::-1] == x[:num] + x[::-1]:
    num += 1

print(num+len(x))