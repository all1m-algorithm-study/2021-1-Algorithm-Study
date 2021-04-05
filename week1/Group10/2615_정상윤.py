import sys
board = []

for i in range(19):
    board.append(list(map(int,sys.stdin.readline().split())))

flag = True
for i in range(19):
    for j in range(19):
        if board[i][j] != 0:
            t = board[i][j]
            #좌우
            if j <= 14:
                if board[i][j+1] == t:
                    if board[i][j+2] == t:
                        if board[i][j+3] == t:
                            if board[i][j+4] == t:
                                if j+5 == 19 or board[i][j+5] != t:
                                    if j-1 == -1 or board[i][j-1] != t:
                                        print(t)
                                        print(i+1,j+1)
                                        flag = False
                                        break
            #상하
            if i <= 14:
                if board[i+1][j] == t:
                    if board[i+2][j] == t:
                        if board[i+3][j] == t:
                            if board[i+4][j] == t:
                                if i+5 == 19 or board[i+5][j] != t:
                                    if i-1 == -1 or board[i-1][j] != t:
                                        print(t)
                                        print(i+1,j+1)
                                        flag = False
                                        break
            #우하 - 좌상               
            if j<=14 and i<=14:
                if board[i+1][j+1] == t:
                    if board[i+2][j+2] == t:
                        if board[i+3][j+3] == t:
                            if board[i+4][j+4] == t:
                                if i+5 == 19 or j+5 == 19 or board[i+5][j+5] != t:
                                    if i-1 == -1 or j-1 == -1 or board[i-1][j-1] != t:
                                        print(t)
                                        print(i+1,j+1)
                                        flag = False
                                        break
            #좌하 - 우상                       
            if i <= 14 and j >= 4:
                if board[i+1][j-1] == t:
                    if board[i+2][j-2] == t:
                        if board[i+3][j-3] == t:
                            if board[i+4][j-4] == t:
                                if i+5 == 19 or j-5 == -1 or board[i+5][j-5] != t:
                                    if i-1 == -1 or j+1 == 19 or board[i-1][j+1] != t:
                                        print(t)
                                        print(i+5,j-3)
                                        flag = False
                                        break
                            

if flag:    
    print(0)


