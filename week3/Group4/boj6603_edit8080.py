# 1. 시작 지점을 변경해나가면서 다음 숫자를 append
# 2. 길이가 탐색할 길이와 동일할 때 여태 append한 문자열을 출력
#
# 시간복잡도 = O(nC6)


def lotto_combination(elements, start, length, result):
    if length == 6:
        return print(result)

    for i in range(start + 1, len(elements)):
        next_result = result + " " + str(elements[i])
        lotto_combination(elements, i, length + 1, next_result)


while True:
    elements = list(map(int, input().split(" ")))

    if elements[0] == 0:
        break

    length = elements.pop(0)

    for i in range(0, len(elements)):
        lotto_combination(elements, i, 1, str(elements[i]))

    print("")
