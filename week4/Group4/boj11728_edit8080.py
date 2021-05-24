# 1. 두 배열을 비교하면서 작은 값을 넣고 해당 배열의 탐색 인덱스를 1 증가시킨다.
# 2. 한 배열의 탐색이 끝나면 나머지 배열은 그대로 집어넣는다.
#
# 시간복잡도 = O(n+m)

n, m = map(int, input().split(" "))
a_list = list(map(int, input().split(" ")))
b_list = list(map(int, input().split(" ")))


def merge(n, m, a_list, b_list):
    ret = []
    i = 0
    j = 0
    while i < n and j < m:
        if a_list[i] < b_list[j]:
            ret.append(a_list[i])
            i += 1
        else:
            ret.append(b_list[j])
            j += 1

    if j == m:
        while i < n:
            ret.append(a_list[i])
            i += 1
    elif i == n:
        while j < m:
            ret.append(b_list[j])
            j += 1

    return ret


ans = merge(n, m, a_list, b_list)
for i in range(n + m - 1):
    print(str(ans[i]) + " ", end="")
print(ans[n+m-1], end="")
