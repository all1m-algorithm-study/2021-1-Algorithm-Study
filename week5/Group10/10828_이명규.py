def stack(a, b = 0):
    if a == 'push':
        arr.append(int(b))
    elif a == 'pop':
        if len(arr)==0:
            print(-1)
        else:
            print(arr[-1])
            arr.pop()
    elif a == 'size':
        print(len(arr))
    elif a == 'empty':
        print(int(len(arr)==0))
    elif a == 'top':
        if len(arr)==0:
            print(-1)
        else:
            print(arr[-1])


N = int(input())
cmd_list = []
for _ in range(N):
    cmd_list.append(input().split())

arr = []
for cmd in cmd_list:
    if len(cmd) == 1:
        stack(cmd[0])
    else:
        stack(*cmd)