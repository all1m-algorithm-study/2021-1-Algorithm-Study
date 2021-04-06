N, L = map(int, input().split())
P = list(map(int, input().split()))
P.sort()
start = P[0]
end = start + L
count = 1
for i in range(N):
    if start <= P[i] and P[i] >= end:
        count += 1
        start = P[i]
        end = start + L
print(count)