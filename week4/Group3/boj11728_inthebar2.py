N, M = map(int, input().split(' '))
n = list(map(int, input().split(' ')))
m = list(map(int, input().split(' ')))

n += m
n.sort()
print(*n)