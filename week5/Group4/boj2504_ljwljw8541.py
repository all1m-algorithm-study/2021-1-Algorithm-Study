#boj2504_ljwljw8541

import sys
input = sys.stdin.readline


def right(str):
    stack = []
    for c in str:
        if c == '[' or c == '(':
            stack.append(c)
        elif c == ']':
            if len(stack) == 0:
                return False
            elif stack[-1] != '[':
                return False
            else:
                stack.pop()
        elif c == ')':
            if len(stack) == 0:
                return False
            elif stack[-1] != '(':
                return False
            else:
                stack.pop()
    if len(stack) != 0:
        return False
    
    return True

def value(str):
    stack = []
    mul = 1
    val = 0
    for c in str:
        if c == '(':
            mul *= 2

        elif c == '[':
            mul *= 3

        elif c == ')':
            if stack[-1] != ')' and stack[-1] != ']':
                val += mul
            mul = mul//2

        elif c == ']':
            if stack[-1] != ')' and stack[-1] != ']':
                val += mul
            mul = mul//3
        stack.append(c)
    return val

bracket = input().rstrip() #.rstrip()안해도 답은 맞음.
if right(bracket):
    print(value(bracket))
else:
    print(0)
