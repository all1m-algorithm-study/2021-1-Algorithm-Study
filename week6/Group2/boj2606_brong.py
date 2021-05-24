from sys import stdin
input = stdin.readline

number_computer = int(input())
number_link = int(input())

graph = [[] for i in range(number_computer+1)]

for i in range(number_link):
    (a,b) = list(map(int,input().split()))
    graph[a].append(b)
    graph[b].append(a)    

def virus(graph, visited, start):
    if visited[start] == 1:
        return 
    visited[start] = 1

    for dest in graph[start]:
        virus(graph, visited, dest)
    return sum(visited)-1

visited = [0]*(number_computer+1)

print(virus(graph,visited, 1 ))



