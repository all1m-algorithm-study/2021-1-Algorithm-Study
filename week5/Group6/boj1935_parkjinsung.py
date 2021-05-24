n = int(input())
postfix = list(input())

alpha_lst = "0 A B C D E F G H I J K L M N O P Q R S T U V W X Y Z".split(" ")
alpha_num = [0]
stack = []
alpha_flag = True

for j in range(n):
    alpha_num.append(int(input()))

for i in range(len(postfix)):
    if postfix[i] in alpha_lst:
        stack.append(alpha_num[ alpha_lst.index(postfix[i]) ])
    else:
        b = stack.pop()
        a = stack.pop()
        if postfix[i] == "-":
            stack.append(a-b)
        elif postfix[i] == "*":
            stack.append(a*b)
        elif postfix[i] == "+":
            stack.append(a+b)
        elif postfix[i] == "/":
            stack.append(a/b)
print('%.2f'%stack[0])
