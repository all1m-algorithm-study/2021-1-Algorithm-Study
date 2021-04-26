target = int(input())
for num in range(target):
    if num + sum(list(map(int, list(str(num))))) == target:
        break

if num == target - 1:
    print(0)
else:
    print(num)