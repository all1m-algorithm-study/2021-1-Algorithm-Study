N, M = map(int, input().split(' '))
cards = list(map(int, input().split(' ')))

max_sum = 0
for i in range(0, len(cards)):
    for j in range(i + 1, len(cards)):
        for k in range(j + 1, len(cards)):
            s = cards[i] + cards[j] + cards[k]
            if s <= M and s > max_sum:
                max_sum = s

print(max_sum)
