def sumArr(i,j,x,y):
    result=0
    for row in range(i,x+1): ## x와 i 사이 그리고 j와 y사이의 값들만 더하면 됨
        result+=sum(board[row][j:y+1]) ## 각 가로축마다 j와 y사이의 값을 더하면 끝
    print(result)


N,M=map(int,input().split())
board=[[0] for _ in range(N+1)]

for i in range(1,N+1):
    board[i]+=list(map(int,input().split()))

K=int(input())

for i in range(K):
    i,j,x,y=map(int,input().split()) ## 여기서부터 좌표값을 저장
    sumArr(i,j,x,y) ## 각 좌표값마다 함수 실행

