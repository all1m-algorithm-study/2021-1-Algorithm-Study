import sys
from itertools import combinations

N, M = map(int, sys.stdin.readline().split())

result = combinations(range(1, N+1), M)

for i in result:
    print(*i)
