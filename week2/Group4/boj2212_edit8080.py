# 1. 모든 좌표를 입력받고 정렬한다.
# 2. 인접한 좌표의 거리를 계산한 후 정렬한다.
# 3. 인접한 좌표의 최대 거리를 k-1번 순차적으로 빼나간다.
#
# 시간복잡도 = O(nlogn) (정렬)

n = int(input())
k = int(input())

cords = list(map(int, input().split(" ")))
cords.sort()

dist = []
for i in range(n-1):
    dist.append(cords[i+1] - cords[i])

dist.sort(reverse=True)
total_distance = cords[n-1] - cords[0]

for i in range(k-1):
    if i >= len(dist):
        break
    total_distance -= dist[i]

print(total_distance)