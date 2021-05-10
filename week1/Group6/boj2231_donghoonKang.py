N = int(input())
result = 0

for i in range(1, 1000000):
    a = i // 100000
    remainder = i % 100000
    b = remainder // 10000
    remainder = remainder % 10000
    c = remainder // 1000
    remainder = remainder % 1000
    d = remainder // 100
    remainder = remainder % 100
    e = remainder // 10
    remainder = remainder % 10
    f = remainder
    num = i + a + b + c + d + e + f
    if num == N:
        result = i
        break

print(result)
