import sys
from itertools import combinations as com

n, s = map(int, sys.stdin.readline().split())
arr = list(map(int,sys.stdin.readline().split()))

cnt = 0
for i in range(1,n+1):
    combi = list(com(arr,i))

    for j in combi:
        if sum(j) == s:
            cnt += 1
    
print(cnt)