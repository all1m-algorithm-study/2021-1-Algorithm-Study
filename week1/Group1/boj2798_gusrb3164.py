N, M = map(int, input().split())
nums = list(map(int, input().split()))

nums.sort()
result = 0

for i in range(len(nums)-2):
    if nums[i] > (M/3):
        break
    for j in range(i+1, len(nums)-1):
        for k in range(j+1, len(nums)):
            if result < nums[i]+nums[j]+nums[k] <= M:
                result = nums[i]+nums[j]+nums[k]

print(result)
