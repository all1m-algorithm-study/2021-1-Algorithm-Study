import sys
input = sys.stdin.readline
from collections import deque
# 개념상 스택과 큐임

n_list = input()
stack = []
number = ['0','1','2','3','4','5','6','7','8','9']
for i in n_list :
    if i in number:
        i=int(i)
        stack.append(i)
    else :
        if i =="\n" :
            break
        top = stack.pop()
        second = stack.pop()
        if i == '+' :
            stack.append(top+second)
        elif i == '-' :
            stack.append(second-top)
        elif i == '*' :
            stack.append(second*top)
        else :
            stack.append(second//top)
print(*stack)