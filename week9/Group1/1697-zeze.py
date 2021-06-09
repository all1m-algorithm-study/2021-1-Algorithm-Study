from collections import deque
import sys

input = sys.stdin.readline

subin_now, goal = map(int, input().split())

time = [0]*100001

que = deque()
# 리스트로 해도 통과는 하지만 더 느림!
# que = []
que.append(subin_now)

def bfs():
    while que:
        now = que.popleft()
        # now = que.pop(0)
        if now == goal:
            print(time[now])
            return
        for next in (now - 1, now + 1, now * 2):
            # print(next)
            if (0 <= next <= 100000) and time[next] == 0:
                time[next] = time[now] + 1
                que.append(next)

bfs()
