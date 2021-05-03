N, L = map(int, input().split())
Location = list (map(int, input().split()))
Location.sort()

cnt = 1
start = Location[0]
finish = start + L - 0.5

for i in range(0, N):
    if finish > Location[i]:
        continue
    else:
        cnt += 1
        finish = Location[i] + L - 0.5

print(cnt)