num_case = int(input())
targets = []
for _ in range(num_case):
    targets.append(int(input()))


def trigonometric(n):
    return int(n * (n + 1) / 2)


def return_bool(target):
    n = 0
    nums = []
    while True:
        n += 1
        if trigonometric(n) > target: break
        nums.append(trigonometric(n))

    for i in range(len(nums)):
        for j in range(len(nums)):
            for k in range(len(nums)):
                if nums[i] + nums[j] + nums[k] == target:
                    return 1
    return 0


for target in targets:
    print(return_bool((target)))


