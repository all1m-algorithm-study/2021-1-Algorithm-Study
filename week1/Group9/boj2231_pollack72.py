N = int(input())

Smallest = 0
for i in range(1, 1000000+1):
    L = []
    for j in range(7):
        L.append((i // 10**j)%10)
    if i + sum(L) == N:
        Smallest = i
        break

print(Smallest)