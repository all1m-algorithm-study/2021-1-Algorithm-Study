import sys
input=sys.stdin.readline

N=int(input())
formula=input()
number=[0]*N

for i in range(N):
    number.append(int(input()))

stack=[]

for i in range(len(formula)):
    if 'A'<=str(i)<='Z':
        stack.append(number[ord(formula[i])-ord('A')])
    elif i == '+':
        b=stack.pop()
        a=stack.pop()
        stack.append(a+b)
    elif i == '-':
        b=stack.pop()
        a=stack.pop()
        stack.append(a-b)
    elif i == '/':
        b=stack.pop()
        a=stack.pop()
        stack.append(a/b)
    elif i == '*':
        b=stack.pop()
        a=stack.pop()
        stack.append(a*b)

print('%.2f' % stack[0])