def main():
    N, M = map(int, input().split())
    list1 = list(map(int, input().split()))
    list2 = list(map(int, input().split()))
    result = []
    idx1 = idx2 = 0
    while idx1 < N and idx2 < M:
        if list1[idx1] < list2[idx2]:
            result.append(list1[idx1])
            idx1 += 1
        else:
            result.append(list2[idx2])
            idx2 += 1
    if idx1 < N:
        result += list1[idx1:]
    else:
        result += list2[idx2:]
    print(' '.join(list(map(str, result))))


if __name__ == "__main__":
    main()
