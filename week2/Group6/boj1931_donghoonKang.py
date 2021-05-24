N = int(input())
times = [[1 for j in range(2)] for i in range(N)]

for i in range(N):
    S, F = map(int, input().split())
    times[i][0] = S
    times[i][1] = F
times.sort(key=lambda x: x[0])
times.sort(key=lambda y: y[1])

nowTime = 0
count = 0

for s, f in times:
    if s >= nowTime:
        nowTime = f
        count += 1

print(count)
