
import sys

dx = [0,0,1,-1]
dy = [1,-1,0,0]

n,m = map(int,sys.stdin.readline().split())
board = []
board_crosssize = [[0 for _ in range(m)]for _ in range(n)]

for i in range(n):
    board.append(list(sys.stdin.readline().rstrip()))

def crosssize(x,y):
    if board[x][y] == '.':
        return 0

    else:
        size_cross = 1

        for i in range(1,100):
            if 0 <= x+i < n and 0 <= x-i <n and 0 <= y+i < m and 0 <= y-i < m:
                if board[x][y+i] == '#' and board[x][y-i] == '#' and board[x+i][y] == '#' and board[x-i][y] == '#':
                    size_cross +=1
                else:
                    return size_cross

            else:
                return size_cross

def cross_real_size(x):
    if x == 0:
        return 0
    else:
        return x*4-3

def overlap_checking(ax,ay,bx,by,an,bn):
    flag = True
    used_cross = [[0 for _ in range(20)]for _ in range(20)]
    used_cross[ax][ay] = 1
    for i in range(1,an):
        used_cross[ax+i][ay] = 1
        used_cross[ax-i][ay] = 1
        used_cross[ax][ay+i] = 1
        used_cross[ax][ay-i] = 1

    if used_cross[bx][by] == 1:
        flag = False
        
    for i in range(1,bn):
        if used_cross[bx+i][by] == 1:
            flag = False
            break
        if used_cross[bx-i][by] == 1:
            flag = False
            break
        if used_cross[bx][by+i] == 1:
            flag = False
            break
        if used_cross[bx][by-i] == 1:
            flag = False
            break

    if flag:
        return False
    else:
        return True

for i in range(n):
    for j in range(m):
        board_crosssize[i][j] = crosssize(i,j)

ans = 0
for ax in range(n):
    for ay in range(m):
        if board[ax][ay] == '#':

            for bx in range(n):
                for by in range(m):
                    if board[bx][by] == '#':
                        
                        for an in range(1, board_crosssize[ax][ay]+1):
                            for bn in range(1, board_crosssize[bx][by]+1):

                                if cross_real_size(an) *  cross_real_size(bn) > ans:
                                    if overlap_checking(ax,ay,bx,by,an,bn) == False:
                                        ans =  cross_real_size(an) *  cross_real_size(bn)
                                        

print(ans)

