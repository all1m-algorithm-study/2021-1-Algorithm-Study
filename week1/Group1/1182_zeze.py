def dfs(index, sum_num):
    global count

    if index == n:
        return

    if sum_num + arr[index] == goal:
        count += 1

    dfs(index + 1, sum_num)
    dfs(index + 1, sum_num + arr[index])


n, goal = map(int, input().split())
arr = list(map(int, input().split()))

count = 0
dfs(0, 0)
print(count)
