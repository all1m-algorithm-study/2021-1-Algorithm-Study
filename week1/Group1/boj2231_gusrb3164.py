n = int(input())

for i in range(n//2, n):
    sum = i
    tmp = i
    while tmp > 0:
        sum += tmp % 10
        tmp //= 10
    if sum == n:
        print(i)
        exit()
print(0)
