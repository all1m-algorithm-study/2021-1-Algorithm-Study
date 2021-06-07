import sys
N = int(input())
deq = []
for _ in range(N):
    arr = sys.stdin.readline().split()
    cmd = arr[0]
    if cmd == 'push_front':
        deq = [int(arr[1])] + deq
    elif cmd == 'push_back':
        deq = deq + [int(arr[1])]
    elif cmd == 'pop_front':
        if len(deq) == 0:
            print(-1)
        else:
            print(deq[0])
            deq.pop(0)
    elif cmd == 'pop_back':
        if len(deq) == 0:
            print(-1)
        else:
            print(deq[-1])
            deq.pop()
    elif cmd == 'size':
        print(len(deq))
    elif cmd == 'empty':
        print(int(len(deq) == 0))
    elif cmd == 'front':
        if len(deq) == 0:
            print(-1)
        else:
            print(deq[0])
    elif cmd == 'back':
        if len(deq) == 0:
            print(-1)
        else:
            print(deq[-1])