# 1. 인덱스를 무게로 사용하고 해당 무게의 밧줄이 입력되었을 때 개수를 1개씩 증가시킨다.
# 2. 현재 밧줄보다 큰 모든 밧줄은 현재 밧줄을 지원해줄 수 있음 (최대값부터 탐색, count를 누적합으로 계산)
#
# 시간복잡도 = O(n)

rope = [0 for _ in range(10001)]

n = int(input())
for _ in range(n):
    weight = int(input())
    rope[weight] += 1

max_weight = 0
count = 0
for i in range(10000, 0, -1):
    if rope[i] != 0:
        count += rope[i]
        if max_weight < count * i:
            max_weight = count * i

print(max_weight)