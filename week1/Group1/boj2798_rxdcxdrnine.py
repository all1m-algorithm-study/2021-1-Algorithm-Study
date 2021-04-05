n, m = map(int, input().split())
nums = list(map(int, input().split()))

old_sum = 0
for i in range(len(nums)):
    for j in range(i + 1, len(nums)):
        for k in range(j + 1, len(nums)):
            new_sum = nums[i] + nums[j] + nums[k]
            if old_sum < new_sum <= m:
                result = new_sum
                old_sum = result

print(result)
