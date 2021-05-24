# 1. 현재의 큐브와 2^i 씩 분할한 크기에 넣는 큐브와 비교한다
# 2. 최적화된 큐브로 계산한 부피와 전체 부피가 같으면 삽입이 가능한 것이니 cnt를 출력한다.
#
# 시간복잡도 = O(n)

box = list(map(int, input().split(" ")))
n = int(input())
cube = [list(map(int, input().split(" "))) for _ in range(n)]
cube.sort()

total = 0
cnt = 0
for i in range(n-1, -1, -1):
    total <<= 3

    # 현재의 큐브와 2^i 씩 분할한 크기에 넣는 큐브와 비교 (앞에서 계산한 최적화 완료 영역은 제외)
    # 분할이 불가능하면 (box >> i)에서 0이 됨

    t = min(cube[i][1], (box[0] >> i) * (box[1] >> i) * (box[2] >> i) - total)
    total += t
    cnt += t


print(cnt if total == box[0]*box[1]*box[2] else -1)
