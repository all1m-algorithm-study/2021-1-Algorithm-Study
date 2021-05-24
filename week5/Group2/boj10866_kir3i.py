from collections import deque
import sys
input = sys.stdin.readline

if __name__ == '__main__':
    N = int(input().strip())
    dq = deque()
    for _ in range(N):
        cmd = list(input().strip().split())
        if cmd[0] == 'push_front':
           dq.appendleft(int(cmd[1]))
        elif cmd[0] == 'push_back':
            dq.append(int(cmd[1]))
        elif cmd[0] == 'pop_front':
            print(dq.popleft() if dq else -1)
        elif cmd[0] == 'pop_back':
            print(dq.pop() if dq else -1)
        elif cmd[0] == 'size':
            print(len(dq))
        elif cmd[0] == 'empty':
            print(0 if dq else 1)
        elif cmd[0] == 'back':
            print(dq[-1] if dq else -1)
        elif cmd[0] == 'front':
            print(dq[0] if dq else -1)
