# 1. n 보다 작은 수들 중 가장 큰 2진수를 찾는다.
# 2. n 에 1에서 구한 값을 빼면서 재귀적으로 탐색한다. (n==1 이 될 때 종료)
# 3. 탐색 횟수를 2로 나눈값을 반환한다. (반전된 횟수)
# ex) 10 -> 2(8감소) -> 1(1감소) => 반전된 횟수 = 2
#
# 시간복잡도 = O(lg n)

k = int(input())


def small_binary(n):
    i = 1
    while i < n:
        i *= 2
    return i // 2


def divide(n, cnt):
    if n == 1:
        return cnt % 2

    diff = small_binary(n)
    return divide(n - diff, cnt + 1)


print(divide(k, 0))
