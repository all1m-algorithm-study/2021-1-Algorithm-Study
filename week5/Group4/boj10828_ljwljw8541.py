#boj10828_ljwljw8541

import sys
input = sys.stdin.readline

N = int(input())
stack = []
for _ in range(N):
    query = input().split()

    #push X: 정수 X를 스택에 넣는 연산이다.
    if query[0] == 'push':
        X = int(query[1])
        stack.append(X)

    #pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다.
    # 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
    elif query[0] == 'pop':
        if len(stack) == 0:
            print(-1)
        else:
            print(stack.pop())

    #size: 스택에 들어있는 정수의 개수를 출력한다.
    elif query[0] == 'size':
        print(len(stack))
    
    #empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
    elif query[0] == 'empty':
        if len(stack) == 0:
            print(1)
        else:
            print(0)
    
    #top: 스택의 가장 위에 있는 정수를 출력한다.
    # 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
    elif query[0] == 'top':
        if len(stack) == 0:
            print(-1)
        else:
            print(stack[-1])


