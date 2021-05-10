N = int(input())
num = N - 1
result = 1000000

while 0 < num < N:
    temp = num
    tempsum = num
    while temp:
        tempsum += temp % 10
        temp = temp - temp % 10
        temp //= 10
        if temp == 0: break  
    if tempsum == N and num < result:
        result = num
    num -= 1

if result == 1000000:
    result = 0

print(result)