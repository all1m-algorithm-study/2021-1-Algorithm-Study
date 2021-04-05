nums = []
while True:
    try:
        num = input()
        if not num: break
        nums.append(int(num))
    except EOFError:
        break

rest = sum(nums) - 100
for num in nums:
    target = rest - num
    if num != target and target in nums:
        nums = [e for e in nums if e not in (num, target)]

for num in nums:
    print(num)