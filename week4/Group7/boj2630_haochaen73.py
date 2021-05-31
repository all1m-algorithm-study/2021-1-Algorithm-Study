paper=[]
def check(row,col,n,white,blue):
    global paper
    first = paper[row][col]
    boolean = True
    for i in range(row,row+n):
        for j in range(col,col+n):
            if paper[i][j]!=first:
                boolean = False
                break
        if boolean == False:
            break

    if boolean == True:
        if first=='0':
            white+=1
        elif first=='1' :
            blue+=1
        return white,blue

    interval = n//2
    white,blue=check(row,col,interval,white,blue)
    white,blue=check(row,col+interval,interval,white,blue)
    white,blue=check(row+interval,col,interval,white,blue)
    white,blue=check(row+interval,col+interval,interval,white,blue)
    return white,blue


N = int(input())
paper=[[' ']*N for v in range(N)]
for i in range (N):
    paper[i]=input().split()

white,blue=check(0,0,N,0,0)
print(white)
print(blue)
