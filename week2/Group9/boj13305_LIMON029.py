N = int(input())
meter = list(map(int, input().split()))
price = list(map(int, input().split()))

p = price[0]
total = price[0] * meter[0]
for i in range(1, N-1):
    if p >= price[i]:
        p = price[i]
    total += p * meter[i]
print(total)