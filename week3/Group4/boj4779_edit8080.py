# 1. 파일 끝까지 입력
# 2. (처음) + (공백) + (끝) 문자열을 목표로 재귀를 돌린다.
# 3. 기저조건 : 길이 == 1
#
# 시간복잡도 = O(n log3(n)) (n = 3^k 계산 횟수)


def cantor(length):
    if length == 1:
        return "-"

    one_three = length // 3
    two_three = (length // 3) * 2

    blank = ""
    for i in range(one_three, two_three):
        blank += " "

    return cantor(length // 3) + blank + cantor(length // 3)


while True:
    try:
        n = int(input())
        length = int(pow(3, n))

        print(cantor(length))

    except EOFError:
        break
