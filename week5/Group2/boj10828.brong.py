from sys import stdin
input = stdin.readline

stack = []
Q = int(input())
for _ in range (Q):
    query = input().split()

    if query[0] == "push":
        item = int(query[1])
        stack.append(item)
    
    if query[0] == "pop":
        if len(stack) == 0 :
            print(-1)
        else:
            print(stack.pop())

    if query[0] == "size":
        print(len(stack))
    
    if query[0] == "empty":
        if len(stack) == 0:
            print(1)
        else:
            print(0)

    if query[0] == "top":
        if len(query) == 0 :
            print(-1)
        else:
            print(stack[-1])