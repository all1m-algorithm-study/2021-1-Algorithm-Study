from sys import stdin
from collections import deque
input = stdin.readline

s, y = list(map(int,input().split()))

def bfs (start, target):
    vst = set([start])
    q = deque([(start, 0)])

    while q:
        curr, dist = q.popleft()
        if curr == target:
            return dist
        for nxt in (curr*2, curr+1, curr-1):
            if nxt not in vst:
                vst.add(nxt)
                q.append((nxt, dist+1))

print(bfs(s,y))






