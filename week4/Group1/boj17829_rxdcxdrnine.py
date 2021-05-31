n = int(input())
arr = []
for _ in range(n):
    arr.append(list(map(int, input().split())))

def divide(arr, N):
    if N == 2:
        return sorted([arr[0][0], arr[0][1], arr[1][0], arr[1][1]])[-2]
    else:
        NW = [arr[i][:N // 2] for i in range(N // 2)]
        NE = [arr[i][N // 2:] for i in range(N // 2)]
        SW = [arr[i][:N // 2] for i in range(N // 2, N)]
        SE = [arr[i][N // 2:] for i in range(N // 2, N)]

        NW = divide(NW, N // 2)
        NE = divide(NE, N // 2)
        SW = divide(SW, N // 2)
        SE = divide(SE, N // 2)
        return sorted([NW, NE, SW, SE])[-2]


print(divide(arr, n))

