N = int(input())
ropes = []
for _ in range(N):
    tmp = int(input())
    ropes.append(tmp)
ropes.sort()

weight = 0
for i in range(N):
    tmp = ropes[i] * (N-i)
    if tmp >= weight:
        weight = tmp

print(weight)
