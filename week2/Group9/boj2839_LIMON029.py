box = 0
N = int(input())

while 1:
    if N % 5 == 0:
        box += N // 5
        print(box)
        break

    N = N - 3
    box += 1

    if N < 0:
        print(-1)
        break