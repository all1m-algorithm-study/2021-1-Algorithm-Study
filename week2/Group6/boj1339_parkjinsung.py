n = int(input())
string_lst = []
for i in range(n):
    string_lst.append(input())

strings = set()
for i in string_lst:
    for j in i:
        strings.add(j)
strings = list(strings)
string_len = len(strings)

check_lst = [] # [[가중치, "알파벳", 0~9중 할당된 숫자]]
for i in range(string_len):
    check_lst.append([0, strings[i]])

for i in range(len(string_lst)):
    dinum = len(string_lst[i])
    for j in range(dinum):
        for k in range(string_len):
            if string_lst[i][j] == check_lst[k][1]:
                check_lst[k][0] += 10 ** (dinum - 1)
        dinum -= 1

check_lst.sort(reverse=True)
result = 0
for i in range(string_len):
    result += check_lst[i][0] * (9 - i)

print(result)
