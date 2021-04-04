N = int(input())
weight = list(map(int, input().split(' ')))
gas = list(map(int, input().split(' ')))


here = 0
money = 0
w = 0
while here < N - 1:
    i = 0
    while here + i < N - 1 and gas[here] <= gas[here + i]:
        w += weight[here + i] * gas[here]
        i += 1
    here += i
print(w)