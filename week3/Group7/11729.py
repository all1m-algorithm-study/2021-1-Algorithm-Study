import sys

N = int(sys.stdin.readline())

# n개의 원판이 있을 경우 가장 밑의 원판을 제외한 나머지를 b로 옮김
# 가장 밑의 원판을 c로 옮기고 b로 옮겨뒀던 나머지들을 다시 c로 옮김


def hanoi(n, a, b, c):
    if n == 1:
        print(a, c)
    else:
        hanoi(n-1, a, c, b)
        print(a, c)
        hanoi(n-1, b, a, c)


cnt = 0

for i in range(N):
    cnt = cnt * 2 + 1

print(cnt)
hanoi(N, 1, 2, 3)
