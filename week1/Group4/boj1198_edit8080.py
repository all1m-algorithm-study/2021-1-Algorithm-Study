# 1. 조합을 통해 세 점 선택 
# 2. 세 점 좌표에 대한 삼각형 넓이 공식 사용
#
# 시간 복잡도 = O(n^3) (combination)

from itertools import combinations


def triArea(triangle):
    return 1 / 2 * abs(
        (triangle[0][0] * triangle[1][1] + triangle[1][0] * triangle[2][1] + triangle[2][0] * triangle[3][1])
        - (triangle[0][1] * triangle[1][0] + triangle[1][1] * triangle[2][0] + triangle[2][1] * triangle[3][0]))


items = []
combination = []
triCords = []

n = int(input())

for i in range(n):
    x, y = input().split()
    triCords.append([int(x), int(y)])

for i in range(n):
    items.append(i)

for i in list(combinations(items, 3)):
    combination.append(list(i))

# 삼각형 최대 넓이 구하기
maxArea = 0
for item in combination:
    triangle = [triCords[item[0]], triCords[item[1]], triCords[item[2]], triCords[item[0]]]
    maxArea = max(maxArea, triArea(triangle))

print(maxArea)