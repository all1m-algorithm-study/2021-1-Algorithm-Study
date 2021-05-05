def main():
    N, B = map(int, input().split())
    matrix = []
    for _ in range(N):
        matrix.append(list(map(int, input().split())))
    result = recur(B, matrix[:])
    for i in result:
        for j in i:
            print(j % 1000, end=' ')
        print()


def recur(B, matrix):
    if B < 2:
        return matrix
    if B % 2 == 1:
        return multi(matrix[:], recur(B-1, matrix[:]))
    else:
        tmp = recur(B//2, matrix[:])
        return multi(tmp, tmp)


def multi(matrix1, matrix2):
    result = []
    for i in range(len(matrix1)):
        tmp = []
        for j in range(len(matrix1)):
            num = 0
            for k in range(len(matrix1)):
                num += matrix1[i][k]*matrix2[k][j]
            tmp.append(num % 1000)
        result.append(tmp)
    return result


if __name__ == "__main__":
    main()
