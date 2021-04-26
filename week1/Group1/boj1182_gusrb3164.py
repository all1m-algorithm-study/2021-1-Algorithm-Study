result = 0


def dfs(SUM, idx):
    if idx >= N:
        return
    if SUM+nums[idx] == S:
        global result
        result += 1
    dfs(SUM+nums[idx], idx+1)
    dfs(SUM, idx+1)


N, S = map(int, input().split())
nums = list(map(int, input().split()))
dfs(0, 0)

print(result)
