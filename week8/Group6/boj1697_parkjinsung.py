#boj1697
from collections import deque
def check_range(nxt):
    return 0 <= nxt <= 100000

def bfs(start, target):
    vst = set([start])
    q = deque([(start, 0)])
    dist = 0
    
    while q:
        pos, dist = q.popleft()
        if pos == target:
            return dist
        
        nexts = [pos+1, pos-1, pos*2]
        for nxt in nexts:
            if (nxt not in vst) and check_range(nxt):
                vst.add(nxt)
                q.append((nxt, dist+1))

start, target = map(int, input().split())
print(bfs(start, target))
