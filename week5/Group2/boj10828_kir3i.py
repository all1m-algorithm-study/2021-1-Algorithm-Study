import sys
input = sys.stdin.readline

if __name__ == '__main__':
    N = int(input().strip())
    st = []
    for _ in range(N):
        cmd = list(input().strip().split())
        if cmd[0] == 'push':
           st.append(int(cmd[1]))
        elif cmd[0] == 'pop':
            print(st.pop() if st else -1)
        elif cmd[0] == 'size':
            print(len(st))
        elif cmd[0] == 'empty':
            print(0 if st else 1)
        elif cmd[0] == 'top':
            print(st[-1] if st else -1)
