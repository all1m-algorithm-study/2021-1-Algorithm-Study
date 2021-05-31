n, m = map(int, input().split())
a_lst = list(map(int, input().split()))
b_lst = list(map(int, input().split()))

result = []
i = 0
j = 0
while (i < len(a_lst) and j < len(b_lst)) == True:
    if a_lst[i] < b_lst[j]:
        result.append(a_lst[i])
        i += 1
    elif b_lst[j] <= a_lst[i]:
        result.append(b_lst[j])
        j += 1

if i < len(a_lst):
    for ii in range(i, len(a_lst)):
        result.append(a_lst[ii])
if j < len(b_lst):
    for jj in range(j, len(b_lst)):
        result.append(b_lst[jj])

print(*result)
