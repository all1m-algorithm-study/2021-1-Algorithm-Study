n=int(input())
array = [list(map(int,input().split())) for i in range(n)]
value =0
answer =0
ans = []

for i in range(n):
    for j in range(n):
        for k in range(n):
            for p in [i,j,k]:
                for q in [i,j,k]:
                    if p==q:
                        value= value+1
            
            if value ==3:            
                answer =abs(0.5*(array[i][0]*array[j][1]+array[j][0]*array[k][1]+array[k][0]*array[i][1]-(array[i][1]*array[j][0]+array[j][1]*array[k][0]+array[k][1]*array[i][0])))
                ans.append(answer)
                
            value = 0
print(max(ans))