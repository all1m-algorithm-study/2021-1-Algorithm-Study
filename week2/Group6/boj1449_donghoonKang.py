N, L = map(int, input().split())
holes = list(map(int, input().split()))
holes.sort()
fixed = [0 for i in range(N)]
count = 0

for j in range(N):
    if fixed[j] == 0:
        fixed[j] == 1
        count += 1
        for k in range(1, N):
            if j+k >= N:
                break
            elif holes[j] - 0.5 + L >= holes[j+k] + 0.5:
                fixed[j+k] = 1
            else:
                break

print(count)
