n, m = list(map(int, input().split()))
list1 = list(map(int, input().split()))
list2 = list(map(int, input().split()))

list_added = list1 + list2

i = 0
j = 0

result = []
while i < n and j < m:
    if list1[i] < list2[j]:
        result.append(list1[i])
        i += 1
    else:
        result.append(list2[j])
        j += 1

if i == n:
    while j < m:
        result.append(list2[j])
        j += 1
else:
    while i < n:
        result.append(list1[i])
        i += 1

for element in result:
    print(element, end=' ')
