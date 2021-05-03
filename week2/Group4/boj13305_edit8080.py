# 1. 주유 가격 기준점 설정
# 2. 더 비싼 주유소가 나오면 거리를 더함(pass)
# 3. 더 싼 주유소가 나오면 주유소 가격, 거리를 통해 금액을 계산한 후 기준점 변경
# 4. 탐색이 끝나면 마지막 기준점에 대한 계산 수행
#
# 시간복잡도 : O(n)

n = int(input())
dists = list(map(int, input().split(" ")))
costs = list(map(int, input().split(" ")))

# 총 거리
dist = dists[0]
# 기준 주유소 가격
cost = costs[0]
min_value = 0

for i in range(1, n-1):
    if costs[i] > cost:
        dist += dists[i]
    else:
        min_value += cost * dist
        dist = dists[i]
        cost = costs[i]

min_value += cost * dist

print(min_value)