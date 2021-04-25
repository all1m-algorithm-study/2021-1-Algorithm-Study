N = int(input())
distances = list(map(int, input().split()))
prices = list(map(int, input().split()))
money = 0
stopIndex = 0

for i in range(N):
    if i < stopIndex:
        continue
    for j in range(i, N):
        if prices[i] > prices[j]:
            stopIndex = j
            break
    if stopIndex == i:
        money += prices[i] * sum(distances[i:N-1])
        break
    else:
        money += prices[i] * sum(distances[i:stopIndex])
    if stopIndex == N-1:
        break

print(money)
