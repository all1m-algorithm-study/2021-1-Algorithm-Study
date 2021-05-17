from collections import deque
import sys
input = sys.stdin.readline

if __name__ == '__main__':
    N = int(input().strip())
    q = deque()
    for _ in range(N):
        cmd = list(input().strip().split())
        if cmd[0] == 'push':
           q.append(int(cmd[1]))
        elif cmd[0] == 'pop':
            print(q.popleft() if q else -1)
        elif cmd[0] == 'size':
            print(len(q))
        elif cmd[0] == 'empty':
            print(0 if q else 1)
        elif cmd[0] == 'back':
            print(q[-1] if q else -1)
        elif cmd[0] == 'front':
            print(q[0] if q else -1)
