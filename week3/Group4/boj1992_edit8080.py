# 1. 전체 일치 여부 탐색
# 2. 전체가 일치하지 않으면 4등분 하여 탐색
# 3. 전체가 일치하거나 길이가 1이 될 때 갯수 +1
# 4. 탐색을 시작할 때 괄호 "(" 종료할 때 ")" 출력
#
# 시간복잡도 = O(n^2 * lg n) (1*1*n^2 + 2*2*(n^2/4) + 4*4*(n^2/16) + ... )

n = int(input())
content = [list(map(int, input())) for _ in range(n)]


def quarter_check(x, y, length):
    standard = content[x][y]

    for i in range(x, x + length):
        for j in range(y, y + length):
            if standard != content[i][j]:
                return False
    return True


def compress_content(x, y, length):
    standard = content[x][y]

    if length == 1:
        print(standard, end="")
        return

    equal = quarter_check(x, y, length)

    if equal:
        print(standard, end="")
    else:
        print("(", end="")
        for i in range(x, x + length, length // 2):
            for j in range(y, y + length, length // 2):
                compress_content(i, j, length // 2)
        print(")", end="")

    return


compress_content(0, 0, n)

