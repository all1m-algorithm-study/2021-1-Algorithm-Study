N = int(input())
ropes = []
for _ in range(N):
    ropes.append(int(input()))
ropes = sorted(ropes)

max_weight = 0
for i in range(N):
    max_weight = max(max_weight, ropes[i] * (N - i))
print(max_weight)