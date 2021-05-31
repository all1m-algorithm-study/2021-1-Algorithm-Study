import sys
input = sys.stdin.readline

n = int(input())
m = int(input())
graph =[ [] for _ in range(m+1)]
for i in range(m) :
    (a,b) = map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)

check_list = []
for j in graph[1] : 
    for k in graph[j] :
        check_list.append(k)


check_list += graph[1]
check_list = set(check_list) 
print(len(check_list)-1)