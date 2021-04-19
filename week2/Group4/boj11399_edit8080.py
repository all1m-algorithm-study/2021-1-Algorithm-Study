#
# 1. 시간이 가장 오래 걸리는 사람을 뒤로 배치한다.
# 2. 누적합은 일정한 공식을 가진다. (k*max[i] + (k-1)*max[i-1] + ... + max[0])
#
# 시간복잡도 = O(n^2) (정렬)
#

n = int(input())
elements = list(map(int, input().split(" ")))
elements.sort(reverse=True)
s = 0

for i in range(1, n+1):
    s += elements[i-1]*i

print(s)
