#boj2644_ljwljw8541
import sys

input = sys.stdin.readline
sys.setrecursionlimit(10**6)

#촌수라고 표현했지만 
#결국은 두 정점간의 최소 노드 수

N = int(input())
P1,P2 = map(int, input().split())
E = int(input())
tree = [[] for _ in range(N+1)]
for _ in range(E):
    x,y = map(int, input().split())
    tree[x].append(y)
    tree[y].append(x)

visited1 = [0]*(N+1)
a = 0
k = 0
def dfs(start,end,count):
    global a,k
    if visited1[start] == 1:
        return
    visited1[start] = 1
    for next in tree[start]:
        if next == end:
            a = 1
            k = count +1 
        else:
            dfs(next,end,count+1)
    return k



visited2 = [0]*(N+1)


if P1 == P2:
    print(0)
    
dfs(P1,P2,k)
if a == 1:
    print(k)
 
else:
    print(-1)