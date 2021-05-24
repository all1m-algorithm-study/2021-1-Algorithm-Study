n, k = map(int, input().split())
num_lst = [i+1 for i in range(n)]
stack = []
temp = k

for _ in range(n):
    if len(num_lst) == 1:
        stack.append(num_lst.pop())
        break
    stack.append(num_lst.pop(temp-1))
    temp = temp + k - 1
    while temp > len(num_lst):
        temp = temp - len(num_lst)
print("<", end = "")
for i in range(len(stack)):
    if i == len(stack)-1:
        print(str(stack[i]), end = "")
    else:
        print(str(stack[i])+", ", end = "")
print(">")
