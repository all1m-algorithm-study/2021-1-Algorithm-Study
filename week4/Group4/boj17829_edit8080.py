# 1. 입력된 배열에 대해 2x2 영역 분할
# 2. 분할한 영역에 대해 2번째로 큰 값을 정렬해서 탐색
# 3. 정렬된 값들로 size/2 x size/2 크기의 배열 생성
# 4. 1~3 과정을 lg n번 반복
#
# 시간복잡도 <= O(n^2 lgn) → 전체 탐색 lg(n)번 수행

n = int(input())
num = [list(map(int, input().split(" "))) for _ in range(n)]


def find(arr, x, y):
    ret = []
    for i in range(2):
        for j in range(2):
            ret.append(arr[x + i][y + j])

    ret.sort(reverse=True)
    return ret[1]


def divide(arr, size):
    result_set = []

    for i in range(0, size, 2):
        result = []
        for j in range(0, size, 2):
            result.append(find(arr, i, j))
        result_set.append(result)

    return result_set


while n > 1:
    num = divide(num, n)
    n //= 2


print(num[0][0])
