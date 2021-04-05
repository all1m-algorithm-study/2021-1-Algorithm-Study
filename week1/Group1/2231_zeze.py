num = int(input())
count = 0
res = []


def div(num):
    while num > 0:
        res.append(num % 10)
        num = num // 10


for i in range(num):
    res.clear()
    div(i)
    sum_res = sum(res)
    if i + sum_res == num:
        print(i)
        exit(0)
print(0)
