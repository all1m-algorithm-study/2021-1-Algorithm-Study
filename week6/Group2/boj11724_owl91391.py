import sys
input = sys.stdin.readline

# 연결요소의 조건
# 연결 요소에 속한 모든 정점을 연결하는 경로가 있어야 한다.
# 또 다른 연결 요소에 속한 정점과 연결하는 경로가 있으면 안된다.

def dfs(con_list,check_list,start) :
    if check_list[start] == 0 :
        return
    check_list[start] = 0

    for dest in con_list[start] :
        dfs(con_list, check_list,dest)


N, M = map(int,input().split())
con_list = [[] for i in range(N+1)]
for i in range(M) :
    (a,b) = list(map(int,input().split()))
    con_list[a].append(b)
    con_list[b].append(a)
ans = 0
check_list = []
for j in range(N+1) :
    check_list.append(j) 


for i in range(1,N+1) :
    if check_list[i] != 0 :
        dfs(con_list, check_list,i)
        ans +=1
print(ans)