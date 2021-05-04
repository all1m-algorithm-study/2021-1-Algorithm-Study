N = int(input())

array = [list(map(int,input().split())) for i in range(N)]
Answer = []

for i in range(N):
    for j in range(N-1):
        for k in range(N-2):
                S = (array[i][0] * array[j+1][1] + array[j+1][0] * array[k+2][1] + array[k+2][0] * array[i][1] - (array[j+1][0] * array[i][1] + array[k+2][0] * array[j+1][1] + array[i][0] * array[k+2][1]))/2
                if S < 0:
                    S = S * (-1)
                Answer.append(S)

Answer.sort()
print(Answer[-1])