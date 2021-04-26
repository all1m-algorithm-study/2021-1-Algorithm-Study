N, M = map(int, input().split())
L = list(map(int, input().split()))

Closest = 0
for i in range(N-2):
    for j in range(i+1, N-1):
        for k in range(j+1, N):
            n = L[i]+L[j]+L[k]
            if n <= M and n > Closest:
                Closest = n
print(Closest)