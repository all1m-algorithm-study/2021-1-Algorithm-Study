N = int(input())
lists = list(input())
num = [0] * N

for i in range(N):
    num[i] = int(input())

stack = []
oper = ['+', '-', '*', '/']

for i in lists:
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
            stack.append(str1 / str2)
    else :
        stack.append(num[ord(i) - ord('A')])
    

print ("%.2f"%stack[0])