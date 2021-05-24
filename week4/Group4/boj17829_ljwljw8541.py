#boj17829_ljwljw8541

N = int(input())

matrix = [list(map(int, input().split())) for _ in range(N)]


def pooling(x1,y1,x2,y2,length):
    if length == 2:
        arr = []
        for i in range(x1,x2):
            for j in range(y1,y2):
                arr.append(matrix[i][j])
        arr.sort()
        return arr[-2]
    a = length//2
    n = length
    z1 = pooling(x1,y1,x1+a,y1+a,a)
    z2 = pooling(x1+a,y1,x1+n,y1+a,a)
    z3 = pooling(x1,y1+a,x1+a,y1+n,a)
    z4 = pooling(x1+a,y1+a,x1+n,y1+n,a)
    K = [z1,z2,z3,z4]
    K.sort()
    return K[-2]
            
print(pooling(0,0,N,N,N))