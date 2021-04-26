#
# 1. 주어진 input의 combination 구한 후 합과 비교
#
# 시간복잡도 = O(2^n) (nC1 + ... nCn)
#
from itertools import combinations

elements = []
n, s = map(int, input().split(" "))
count = 0

elements = list(map(int, input().split(" ")))

for i in range(1, n + 1):
    for combinate in combinations(elements, i):
        if sum(list(combinate)) == s:
            count += 1

print(count)