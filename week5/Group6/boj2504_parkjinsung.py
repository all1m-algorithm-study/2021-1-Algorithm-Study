string = input()
stack = []

for i in range(len(string)):
    stack.append(string[i])
    if len(stack) >= 2:
        if stack[-2] == '(' and stack[-1] == ')':
            stack.pop()
            stack.pop()
            stack.append(2)
        elif stack[-2] == '[' and stack[-1] == ']':
            stack.pop()
            stack.pop()
            stack.append(3)
    if len(stack) >= 3:
        if stack[-3] == '(' and type(stack[-2]) == int and stack[-1] == ')':
            stack.pop()
            x = stack.pop()
            stack.pop()
            stack.append(x*2)
        elif stack[-3] == '[' and type(stack[-2]) == int and stack[-1] == ']':
            stack.pop()
            x = stack.pop()
            stack.pop()
            stack.append(int(x*3))
    if len(stack) >= 2 and type(stack[-2]) == int and type(stack[-1]) == int:
        stack.append(stack.pop() + stack.pop())

if len(stack) == 1 and type(stack[0]) == int:
    print(stack[0])
else:
    print(0)
