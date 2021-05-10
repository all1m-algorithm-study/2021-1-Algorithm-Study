N = int(input())

cnt = 0
for i in range(N//5, 0, -1):
    if (N - (i * 5)) % 3 == 0:
        N -= (i * 5)
        cnt = i
        break
if N % 3 == 0:
    cnt += N // 3
else:
    cnt = -1

print(cnt)
