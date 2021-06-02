line = list(input())
n = len(line)
stack = []
for i in range(n):
    if ord(line[i]) in range(48, 57 + 1):
        stack.append(int(line[i]))
    else:  # 연산자 나오면 이전 2개 숫자로 연산
        operator = line[i]
        a, b = stack[-2], stack[-1]
        stack.pop()
        stack.pop()
        if operator == '+':
            stack.append(a+b)
        if operator == '-':
            stack.append(a-b)
        if operator == '*':
            stack.append(a*b)
        if operator == '/':
            stack.append(int(a/b))
print(stack[0])