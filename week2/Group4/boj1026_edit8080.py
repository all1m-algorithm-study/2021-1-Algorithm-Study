#
# 1. 두 배열의 곱의 합이 최소가 되는 경우는 (최소)*(최대) 일 때이다.
#
# 시간복잡도 = O(n^2) (정렬)
#
n = int(input())

a = list(map(int, input().split(" ")))
b = list(map(int, input().split(" ")))

a.sort()
b.sort(reverse=True)
s = 0

for i in range(n):
    s += a[i]*b[i]

print(s)