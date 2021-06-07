#boj11725_ljwljw8541
from sys import stdin
input = stdin.readline
from sys import setrecursionlimit

N = int(input())
setrecursionlimit(2*N)

graph = [[] for _ in range(N+1)]

for _ in range(N-1):
    x,y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)

#k는 각 자식(index로 표현)의 부모노드 리스트
#값이 0 인것은 아직 부모노드를 저장하지 않은것
def find(parents,k):
    
    for child in graph[parents]:
        if k[child] == 0:
            k[child] = parents
            find(child,k)
    return k
k = [0]*(N+1)
find(1,k)
for c in k[2:]:
    print(c)
print(graph)