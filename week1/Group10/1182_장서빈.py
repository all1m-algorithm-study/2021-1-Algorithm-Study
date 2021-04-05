n, s = map(int, input().split())
list = list(map(int, input().split()))
count = 0
i = 1
while i<2**n:
    switch = bin(i)
    sum = 0
    for j in range(-1*(len(switch)-2),0):
        if switch[j] == '1':
            sum += list[j]
    if sum == s:
        count += 1
    i += 1

print(count)