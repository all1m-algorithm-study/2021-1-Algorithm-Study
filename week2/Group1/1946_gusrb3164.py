def main():
    t = int(input())
    for _ in range(t):
        N = int(input())
        result, emps, max_score = 1, [], 0
        for _ in range(N):
            emps.append(tuple(map(int, input().split())))
        emps.sort()
        max_score = emps[0][1]

        for i in range(1, N):
            if emps[i][1] < max_score:
                result += 1
                max_score = emps[i][1]
        print(result)


if __name__ == "__main__":
    main()
