import sys
from itertools import combinations

arr = []

for _ in range(9):
    arr.append(int(sys.stdin.readline()))

answer = sum(arr) - 100

for compute in combinations(arr, 2):
    if sum(compute) == answer:
        arr.remove(compute[0])
        arr.remove(compute[1])

for each in arr:
    print(each)