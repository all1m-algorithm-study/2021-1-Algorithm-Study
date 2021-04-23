N = int(input())
Ps = list(map(int, input().split(' ')))

Ps = sorted(Ps)
total = 0
waited = 0
for i in range(N):
    total += waited + Ps[i]
    waited = waited + Ps[i]
print(total)