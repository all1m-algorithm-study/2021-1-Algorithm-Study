#boj1987_ljwljw8541
import sys
input = sys.stdin.readline

R,C = map(int, input().split())
matrix = [list(map(lambda x: ord(x)-65,input())) for _ in range(R)]
alphabet = [True]*26
#오,아래,왼,위
kx = [0,1,0,-1]
ky = [1,0,-1,0]

answer = 0

def dfs(x,y,depth):
    global answer
    
    
    answer = answer if answer>depth else depth

    for i in range(4):
        dx = x + kx[i]
        dy = y + ky[i]
        
        if 0<=dx<R and 0<=dy<C:
            ch = matrix[dx][dy]
            if alphabet[ch]:

                alphabet[ch] = False

                dfs(dx,dy,depth+1)

                alphabet[ch] = True
    
alphabet[matrix[0][0]] = False
dfs(0,0,1)
print(answer)