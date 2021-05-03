def dfs(start, depth):
    if depth == 6:
        for i in range(6):
            print(combi[i], end=' ')
        print()
        return
    for i in range(start, len(s)):
        combi[depth] = s[i]
        dfs(i + 1, depth + 1)


combi = [0 for i in range(13)]

while True:
    s = list(map(int, input().split()))
    if s[0] == 0:
        break
    del s[0]  # input의 첫 숫자는 배열의 길이이므로 빼줘야함
    dfs(0, 0)
    print()