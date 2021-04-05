from collections import Counter

n = int(input())

questions = []
for _ in range(n):
    questions.append(list(map(int, input().split())))

def check(num):
    list_num = list(str(num))

    if '0' in list_num:
        return

    if len(Counter(list_num)) != 3:
        return

    for question in questions:
        req, strike, ball = question

        list_req = list(str(req))
        filtered_num = [list_num[i] for i in range(3) if list_num[i] != list_req[i]]
        filtered_req = [list_req[i] for i in range(3) if list_num[i] != list_req[i]]
        if 3 - len(filtered_num) != strike:
            return

        list_ball = [digit for digit in filtered_num if digit in filtered_req]
        if len(list_ball) != ball:
            return

    return num

res = []
for num in range(111, 999):
    if num := check(num):
        res.append(num)

print(len(res))