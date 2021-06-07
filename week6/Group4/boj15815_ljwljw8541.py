#boj15815_ljwljw8541
from sys import stdin
input = stdin.readline

def calculate(postfix):
    stack = []
    k = 0
    
    for c in postfix:
        if c == '+' or c == '-' or c== '*' or c == '/':
            if c == '+':
                k = int(stack[-2])+int(stack[-1])

            elif c == '-':
                k = int(stack[-2])-int(stack[-1])

            elif c == '*':
                k = int(stack[-2])*int(stack[-1])

            elif c == '/':
                k = int(stack[-2])//int(stack[-1])
                

            stack.pop()
            stack.pop()
            stack.append(k)
        
        else:
            stack.append(c)
    return stack[0]

postfix = str(input())
print(calculate(postfix))
