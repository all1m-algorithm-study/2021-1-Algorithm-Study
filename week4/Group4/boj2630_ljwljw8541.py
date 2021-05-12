#boj2630_ljwljw8541
#쿼드트리의 응용문제
#쿼드트리에서 0과 1이 얼마나 있는가?
N = int(input())
matrix = [list(map(str, input().split())) for _ in range(N)]

    
def Quarter(x1,y1,x2,y2,n):#x1,y1 시작점 x2,y2 끝점 n 배열의 가로세로 크기
    if n == 1:
        return matrix[x1][y1] #x1은 세로 y1은 가로
    a = n//2
    z1 = Quarter(x1,y1,x1+a,y1+a,a)
    z2 = Quarter(x1,y1+a,x1+a,y1+n,a)
    z3 = Quarter(x1+a,y1,x1+n,y1+a,a)
    z4 = Quarter(x1+a,y1+a,x1+n,y1+n,a)
    if z1 == z2 == z3 == z4 and len(z1) == 1:
        return z1
    else:
        return '('+ z1 + z2 + z3 + z4 + ')'
K = str(Quarter(0,0,N,N,N))
print(K.count('0'))
print(K.count('1'))

