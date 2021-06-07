from sys import stdin
from collections import deque
input = stdin.readline

s, y = list(map(int,input().split()))


vst = set([s])
q = deque([(s, 0)])

while q:
    curr, dist = q.popleft()
    if curr == y:
        print(dist)
    for nxt in (curr*2, curr+1, curr-1):
        if 0<= nxt <= 100000 and nxt not in vst:
            vst.add(nxt)
            q.append((nxt, dist+1))








