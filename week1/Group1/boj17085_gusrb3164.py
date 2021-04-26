# 해당 점에서 최대 크기를 구하고 정보를 넣는 함수
def search(row, col):
    size = 0
    while -1 < row-size and row+size < N and -1 < col-size and col+size < M and board[row-size][col] == board[row+size][col] == board[row][col-size] == board[row][col+size] == '#':
        size += 1
    while size:  # 작은 경우끼리 곱하는게 더 클 수도 있으므로 고려해야함
        dotInfo.append([size, row, col])
        size -= 1

# 점 2개 부분이 서로 안겹치는지 유효성 검사


def test(dot1, dot2):
    testBoard = [[0]*M for _ in range(N)]
    d = [[-1, 0], [1, 0], [0, -1], [0, 1]]

    for i in range(dot1[0]):
        for j in range(4):
            testBoard[dot1[1]+d[j][0]*i][dot1[2]+d[j][1]*i] = 1

    for i in range(dot2[0]):
        for j in range(4):
            if testBoard[dot2[1]+d[j][0]*i][dot2[2]+d[j][1]*i] == 1:
                return False  # 겹친다면 False 반환
    return True


N, M = map(int, input().split())
board = []
dotInfo = []
result = 0
for _ in range(N):
    board.append(str(input()))

for r in range(N):
    for c in range(M):
        if board[r][c] == '#':
            search(r, c)  # 인 부분 정보 저장

for i in range(len(dotInfo)-1):
    for j in range(i+1, len(dotInfo)):
        mul = (1+(dotInfo[i][0]-1)*4)*(1+(dotInfo[j][0]-1)*4)
        # 현재 값보다 큰 경우만 test로 유효성 검사
        if mul > result and test(dotInfo[i], dotInfo[j]):
            result = mul

print(result)
