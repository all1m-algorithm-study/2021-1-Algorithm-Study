# 1. 중앙의 좌표를 기준으로 잡고 탐색할 좌표가 속할 사분면을 찾는다. (like 이진 탐색)
# 2. 각 사분면에 맞게 order 값을 증가시키고 4등분씩 분할해 재귀적으로 탐색한다.
# 3. 탐색할 좌표와 일치하면 order 값을 return 한다.
#
# 시간복잡도 = O(lg n)


n, r, c = map(int, input().split(" "))


def z_traversal(x, y, length, order):
    if x == r and y == c:
        return order

    middle_x = x + length // 2
    middle_y = y + length // 2
    step = length // 2 * length // 2

    if r < middle_x and c < middle_y:
        return z_traversal(x, y, length // 2, order)

    elif r < middle_x and c >= middle_y:
        return z_traversal(x, middle_y, length // 2, order + step)

    elif r >= middle_x and c < middle_y:
        return z_traversal(middle_x, y, length // 2, order + step * 2)

    elif r >= middle_x and c >= middle_y:
        return z_traversal(middle_x, middle_y, length // 2, order + step * 3)


print(z_traversal(0, 0, pow(2, n), 0))