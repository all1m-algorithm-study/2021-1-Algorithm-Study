Q = 25
D = 10
N = 5
P = 1

T = int(input())
c = []
C = 0
for i in range(T):
    C = int(input())
    c.append([])
    c[i].append(C // Q)
    C = C % Q
    c[i].append(C // D)
    C = C % D
    c[i].append(C // N)
    C = C % N
    c[i].append(C // P)
    C = C % P

for i in range(T):
    for j in range(4):
        print(c[i][j], end=" ")
    print()