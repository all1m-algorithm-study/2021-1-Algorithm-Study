# 1. 5*i + 3*j == n 이 되는 모든 경우를 탐색하고 (i+j)가 최솟값이 되는 경우를 출력한다.
#
# 시간복잡도 = O(n^2)

def count(n):
    min_count = 1700
    for i in range(n//5 + 1):
        for j in range(n//3 + 1):
            check = 5*i + 3*j
            if check == n:
                if min_count > i+j:
                    min_count = i+j

            elif check > n:
                break

    if min_count == 1700:
        return -1
    return min_count


n = int(input())
print(count(n))