num = int(input())

arr = []
count_arr = []

quarter = 25
dime = 10
nickel = 5
penny = 1

# 입력받기
for _ in range(num):
    arr.append(int(input()))

for i in arr:
    count = 0
    while i >= quarter:
        i -= quarter
        count += 1
    count_arr.append(count)
    count = 0
    while i >= dime:
        i -= dime
        count += 1
    count_arr.append(count)
    count = 0
    while i >= nickel:
        i -= nickel
        count += 1
    count_arr.append(count)
    count = 0
    while i >= penny:
        i -= penny
        count += 1
    count_arr.append(count)
    count = 0

# 출력
for j in range(0, len(count_arr), 4):
    print(' '.join(map(str, count_arr[j:j+4])))
