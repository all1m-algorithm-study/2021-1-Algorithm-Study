def main():
    N = int(input())
    meets = []
    for _ in range(N):
        meets.append(list(map(int, input().split())))
    meets.sort()
    result = []
    for meet in meets:
        if len(result) == 0 or result[-1][1] <= meet[0]:
            result.append(meet)
        elif result[-1][1] > meet[1]:
            result.pop(-1)
            result.append(meet)
    print(len(result))


if __name__ == '__main__':
    main()
