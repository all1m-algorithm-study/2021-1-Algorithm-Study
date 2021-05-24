import sys
from collections import deque
input = sys.stdin.readline

if __name__ == '__main__':
    N, K = map(int, input().strip().split())
    q = deque([i for i in range(1, N+1)])
    ans = []
    while q:
        for _ in range(K-1):
            q.append(q.popleft())
        ans.append(str(q.popleft()))

    print('<' + ', '.join(ans) + '>')
