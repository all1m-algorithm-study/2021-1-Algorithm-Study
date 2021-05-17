result = [0, 0, 0, 0]


def main():
    n = int(input())
    global left, right, result
    left = int(input())
    right = int(input())
    N = int(input())

    recur(0, 3**N-1, n)
    for i in range(1, 4):
        print(result[i], end=' ')


def recur(cur_left, cur_right, n):
    if cur_left == cur_right:
        global result
        result[n] += 1
        return
    size = (cur_right-cur_left+1)//3
    ranges = [(cur_left, cur_left+size-1), (cur_left+size,
                                            cur_right-size), (cur_right-size+1, cur_right)]
    next_txt = '132'
    if n == 2:
        next_txt = '211'
    elif n == 3:
        next_txt = '232'
    for i in range(3):
        if range_test(ranges[i]):
            recur(ranges[i][0], ranges[i][1], int(next_txt[i]))


def range_test(ranges):
    if (left <= ranges[0] <= right) or (left <= ranges[1] <= right):
        return True
    return False


if __name__ == "__main__":
    main()
