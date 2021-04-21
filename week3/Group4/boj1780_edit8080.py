# 1. 전체 일치 여부 탐색
# 2. 전체가  일치하지 않으면 9등분 하여 탐색
# 3. 전체가 일치하거나 길이가 1이 될 때 갯수 +1
#
# 시간복잡도 = O(n^2 * log3(n))

paper = []
n = int(input())

for _ in range(n):
    element = list(map(int, input().split(" ")))
    paper.append(element)

paper_count = [0 for _ in range(3)]


def is_equal(standard, x, y, length):
    for i in range(x, x + length):
        for j in range(y, y + length):
            if standard != paper[i][j]:
                return False
    return True


def cutting(x, y, length):
    standard = paper[x][y]

    if length == 1:
        paper_count[standard + 1] += 1
        return

    equal = is_equal(standard, x, y, length)

    if equal:
        paper_count[standard + 1] += 1

    else:
        for i in range(x, x + length, length // 3):
            for j in range(y, y + length, length // 3):
                cutting(i, j, length // 3)

    return


cutting(0, 0, n)
for i in range(3):
    print(paper_count[i])

