n = int(input())
arr = []
for _ in range(n):
    arr.append(list(map(int, input().split())))


def divide(arr, N):
    view = []
    for row in arr:
        view.extend(row)

    if list(set(view)) == [0]:
        return 1, 0
    if list(set(view)) == [1]:
        return 0, 1
    else:
        NW = [arr[i][:N // 2] for i in range(N // 2)]
        NE = [arr[i][N // 2:] for i in range(N // 2)]
        SW = [arr[i][:N // 2] for i in range(N // 2, N)]
        SE = [arr[i][N // 2:] for i in range(N // 2, N)]

        NW = divide(NW, N // 2)
        NE = divide(NE, N // 2)
        SW = divide(SW, N // 2)
        SE = divide(SE, N // 2)

        result = [0, 0]
        for fraction in [NW, NE, SW, SE]:
            result[0] += fraction[0]
            result[1] += fraction[1]
        return result


result = divide(arr, n)
for num in result:
    print(num)
