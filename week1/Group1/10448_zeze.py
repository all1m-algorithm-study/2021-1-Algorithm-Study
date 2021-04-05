num = int(input())
arr = []
circle = []
for _ in range(num):
    arr.append(int(input()))

for i in range(1, 56):
    circle.append((i*(i+1))//2)


def brute(num):
    for i in circle:
        for j in circle:
            for k in circle:
                if i + j + k == num:
                    return True


for num in arr:
    if brute(num):
        print(1)
    else:
        print(0)
