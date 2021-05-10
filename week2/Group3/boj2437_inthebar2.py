N = int(input())
weights = sorted(list(map(int, input().split(' '))))

measure = 1
for i in range(N):
    if measure < weights[i]:
        break
    measure += weights[i]

print(measure)