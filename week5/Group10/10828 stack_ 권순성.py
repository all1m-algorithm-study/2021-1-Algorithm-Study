import sys
def push(num):
    stack.append(num)
def pop():
    if not stack:
        return -1
    else:
        return stack.pop()
def size():
    return len(stack)
def empty():
    if not stack:
        return 1
    else:
        return 0
    def top():
        if not stack:
            return -1
        else:
            return stack[-1]
    stack=[]
    N=int(sys.stdin.readline())


for i in range(N):
    answer=sys.stdin.readline().rstrip().split()
    cmd=answer[0]
    if cmd== "push":
        push(answer[1])
    elif cmd== "pop":
        print(stack.pop())
    elif cmd =="size":
        print(stack.size())
    elif cmd == "empty":
        print(stack.empty())
    elif cmd == "top":
        print(stack.top())


        
