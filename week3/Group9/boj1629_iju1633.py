A, B, C = map(int, input().split(" "))

for i in range(B-1):
    A *= B
    A /= C

print(int(A))


