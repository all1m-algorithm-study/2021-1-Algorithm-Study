# 1. 시작 지점을 변경해나가면서 다음 숫자를 append
# 2. 길이가 탐색할 길이와 동일할 때 여태 append한 문자열을 출력
# ex) 1 2 - 1 2 3 (3 append)
#         \ 1 2 4 (4 append)
#
# 시간복잡도 = O(nCm)

n, m = map(int, input().split(" "))
numbers = []
for i in range(1, n+1):
    numbers.append(str(i))


def combination(start, length, string):
    if length == m:
        return print(string)

    for j in range(start + 1, n):
        nextString = string + " " + numbers[j]
        combination(j, length+1, nextString)

    return


for i in range(n):
    combination(i, 1, numbers[i])
