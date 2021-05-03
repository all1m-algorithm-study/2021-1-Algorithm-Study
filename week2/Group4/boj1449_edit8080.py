# 1. 테이프를 최대한 늘렸을 때 커버할 수 있는 최대 크기만큼 탐색한다.
# 2. 만약 테이프로 균열을 메울 수 없으면 이전 영역까지 균열을 메우고 탐색 지점을 이동한다.
# 주의) 균열의 위치가 무작위로 들어올 수 있음
#
# 시간복잡도 = O(n^2) (정렬)

n, tape = map(int, input().split(" "))
pipe = list(map(int, input().split(" ")))

standard = 0
count = 0

pipe.sort()

for i in range(n):
    if pipe[i] - pipe[standard] + 1 > tape:
        count += 1
        standard = i

count += 1

print(count)