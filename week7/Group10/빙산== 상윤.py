빙산=========

import sys

dx = [0,0,1,-1]
dy = [1,-1,0,0]

n,m = map(int,input().split())
icebergs = []
for i in range(n):
    icebergs.append(list(map(int,sys.stdin.readline().split())))

def dfs(x,y):
    q = [[x,y]]
    # visited = [[0 for _ in range(m)]for _ in range(n)]
    visited[x][y] = 1

    while q:
        a = q.pop()

        nowx = a[0]
        nowy = a[1]

        for i in range(4):
            newx = nowx + dx[i]
            newy = nowy + dy[i]

            if 0<=newx<n and 0<=newy<m:
                if icebergs[newx][newy] != 0:
                    if visited[newx][newy] != 1:       
                        q.append([newx,newy])
                        visited[newx][newy] = 1

def melt():
    howmuch = [[0 for _ in range(m)]for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if icebergs[i][j] != 0:
                
                melt_counter = 0
                for dsnb in range(4):
                    if 0<=i+dx[dsnb]<n and 0<=j+dy[dsnb]<m:
                        if icebergs[i+dx[dsnb]][j+dy[dsnb]] == 0:
                            melt_counter += 1
            
                howmuch[i][j] = melt_counter

    for i in range(n):
        for j in range(m):
            if icebergs[i][j] != 0:
                icebergs[i][j] = max(icebergs[i][j] - howmuch[i][j],0)

cnt = -1

while True:
    visited = [[0 for _ in range(m)]for _ in range(n)]
    check_all_melted = True
    check_answer_accepted = False
    cnt += 1

    flag = True
    for i in range(n):
        for j in range(m):
            if icebergs[i][j] != 0 and flag == True:
                used = [i,j]
                flag = False
            elif flag == False:
                break

    
                # check_all_melted = False
                # dfs(i,j)
                # print(i,j)
                # break
    
    if flag == True:
        print(0)
        break
    else:
        dfs(used[0],used[1])
    
    if dx[0] == 100000:
        pass
    else:
        # print(icebergs)
        # print(visited)
        for i in range(n):
            for j in range(m):
                if icebergs[i][j] > 1 and visited[i][j] == 0:
                    # print(i,j)
                    check_answer_accepted = True
                    break

                     
    if check_answer_accepted:
        print(cnt)
        break
    melt()
