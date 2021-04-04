def search(row, col, dir):
    for i in range(1, 5):
        if board[row+i*dir[0]][col+i*dir[1]] != board[row][col]:
            return False
    if -1 < row+5*dir[0] < 19 and -1 < col+5*dir[1] < 19 and board[row+5*dir[0]][col+5*dir[1]] == board[row][col]:
        return False
    if -1 < row-1*dir[0] < 19 and -1 < col-1*dir[1] < 19 and board[row-1*dir[0]][col-1*dir[1]] == board[row][col]:
        return False
    return True


board = []
for _ in range(19):
    board.append(list(map(int, input().split())))

# ↘ 방향 계산
for row in range(15):
    for col in range(15):
        if board[row][col] != 0 and search(row, col, [1, 1]):
            print(board[row][col])
            print(row+1, col+1)
            exit()
# → 방향 계산
for row in range(19):
    for col in range(15):
        if board[row][col] != 0 and search(row, col, [0, 1]):
            print(board[row][col])
            print(row+1, col+1)
            exit()
# ↓ 방향 계산
for row in range(15):
    for col in range(19):
        if board[row][col] != 0 and search(row, col, [1, 0]):
            print(board[row][col])
            print(row+1, col+1)
            exit()
# ↗ 방향 계산
for row in range(4, 19):
    for col in range(15):
        if board[row][col] != 0 and search(row, col, [-1, 1]):
            print(board[row][col])
            print(row+1, col+1)
            exit()

print(0)
