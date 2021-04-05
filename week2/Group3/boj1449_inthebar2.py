N, L = map(int, input().split(' '))
leaks = sorted(list(map(int, input().split(' '))))

end = 0
cnt = 0
for i in range(N):
    if end < leaks[i]:
        start = leaks[i] - 0.5
        end = start + L
        cnt += 1
print(cnt)