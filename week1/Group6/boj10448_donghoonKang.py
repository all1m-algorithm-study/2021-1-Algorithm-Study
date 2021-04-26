N = int(input())
numbers = [int(input()) for _ in range(N)]


def triChecker(checkNum):
    for i in range(1, 46):
        for j in range(1, 46):
            for k in range(1, 46):
                tri = (i*(i+1))/2 + (j*(j+1))/2 + (k*(k+1))/2
                if tri == checkNum:
                    return 1
    return 0


for n in numbers:
    print(triChecker(n))
