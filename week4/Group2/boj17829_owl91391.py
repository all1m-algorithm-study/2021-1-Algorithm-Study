import sys
input = sys.stdin.readline

def list_chunk(arr,k) :
    return [arr[i:i+k] for i in range(0,len(arr),k)]

def pooling(arr,num) :
    if len(arr) ==2 :
        p_arr = []
        p_arr = arr[0] + arr[1]
        p_arr.remove(max(p_arr))
        return max(p_arr)
    else :
        pool_arr = [0]*num
        pooling_arr=[ [0 for _ in range(num//2)] for _ in range(num//2) ]
        for i in range(num) :
             pool_arr[i] = list_chunk(arr[i],2)
        for i in range(0,num,2) :
            for j in range(0,num//2) :
                if i ==0 :
                    pooling_arr[i][j] = pool_arr[i][j] + pool_arr[i+1][j]
                else :
                    pooling_arr[i//2][j] = pool_arr[i][j] + pool_arr[i+1][j]
        for k in range(num//2) :
            for u in range(num//2) :
                pooling_arr[k][u].remove(max(pooling_arr[k][u]))
                pooling_arr[k][u] = max(pooling_arr[k][u])
        return pooling(pooling_arr,len(pooling_arr))



n=int(input())
arr=[list(map(int,input().split())) for _ in range(n)]
answer = pooling(arr,len(arr))
print(answer)