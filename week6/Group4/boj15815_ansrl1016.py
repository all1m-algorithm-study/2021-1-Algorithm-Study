cal = input()
stack=[]
oper = ['+', '-', '*', '/']

for i in cal:
    if i in oper :
        str2 = stack.pop()
        str1 = stack.pop()

        if i == '+':
            stack.append(str1 + str2)
        elif i == '-':
            stack.append(str1 - str2)
        elif i == '*':
            stack.append(str1 * str2)
        elif i == '/':
            if str1%str2 == 0:
                stack.append(int(str1 / str2))
            else:
                stack.append(str1/str2)
                
    else:
        stack.append(int(i))

print(stack[0])