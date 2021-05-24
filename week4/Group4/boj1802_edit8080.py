# 1. 접기 규칙 결과 : 중앙을 기준으로 left, right 가 서로 반전 대칭이어야한다. (ex : left=100 right=110)
# 2. 중앙을 기준으로 분할
# 3. left, right가 서로 반전 대칭인지 확인
#
# 시간복잡도 = O(nlgn) 문자열길이 * 중앙 분할횟수

t = int(input())
check = [input() for _ in range(t)]
correct = True


def is_reverse(left, right, length):
    for i in range(length):
        if left[i] == right[length - i - 1]:
            return False
    return True


def divide(string, length):
    global correct
    if length == 1:
        return string

    half = length // 2

    left = divide(string[0:half], half)
    right = divide(string[half + 1:], half)

    if not is_reverse(left, right, half):
        correct = False

    return string


for i in range(t):
    correct = True
    divide(check[i], len(check[i]))
    print("YES" if correct else "NO")
