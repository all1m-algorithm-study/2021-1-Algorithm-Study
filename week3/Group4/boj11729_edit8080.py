# 1. (n-1)개의 원판을 가운데로 옮긴다.
# 2. n번째 원판을 오른쪽으로 옮긴다.
# 3. (n-1)개의 원판을 오른쪽으로 옮긴다.
# 4. 위 과정을 재귀적으로 진행한다.
# 5. 원판이 1개 남은 경우 오른쪽으로 옮긴다.
#
# 시간복잡도 = O(2^n)

n = int(input())
moving = []
print(pow(2, n) - 1)


def Hanoi(cnt, start, space, end):
    if cnt == 1:
        print(start + " " + end)
        return

    Hanoi(cnt - 1, start, end, space)
    print(start + " " + end)
    Hanoi(cnt - 1, space, start, end)

    return


Hanoi(n, "1", "2", "3")