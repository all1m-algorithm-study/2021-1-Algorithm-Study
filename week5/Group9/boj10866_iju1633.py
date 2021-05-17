import sys

input = sys.stdin.readline
deque = []
n = int(input())

for i in range(n):
    command = input().rstrip()
    if " " in command:
        a, b = command.split()
        if a == 'push_front':
            deque.insert(0, b)
        elif a == 'push_back':
            deque.append(b)
    elif "pop_front" == command:
        if len(deque) == 0:
            print(-1)
        else:
            print(deque.pop(0))
    elif "pop_back" == command:
        if len(deque) == 0:
            print(-1)
        else:
            print(deque.pop(-1))

    elif 'size' == command:
        print(len(deque))
    elif 'empty' == command:
        if len(deque) == 0:
            print(1)
        else:
            print(0)
    elif 'front' == command:
        if len(deque) == 0:
            print(-1)
        else:
            print(deque[0])
    elif 'back' == command:
        if len(deque) == 0:
            print(-1)
        else:
            print(deque[-1])