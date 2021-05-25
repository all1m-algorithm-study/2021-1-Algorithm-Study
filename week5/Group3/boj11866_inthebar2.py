N, K = map(int, input('').split(' '))

s = [i for i in range(1, N + 1)]
result = []
idx = 0
cnt = 0

while len(s) > 0 :
    idx += (K - 1)
    idx %=  (N - cnt)
    result.append(s.pop(idx))
    cnt+= 1

print('<', end='')
for i in range(N):
    if i == N - 1:
        print(result[i], end='>')
    else:
    	print(result[i], end=', ')

