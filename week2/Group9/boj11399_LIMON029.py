N = int(input())
P = list(map(int, input().split()))

P.sort()

result = 0
waiting = 0
for i in P:
    result += i + waiting
    waiting += i

print(result)
