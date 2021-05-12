import sys
input = sys.stdin.readline

def list_chunk(arr,k) :
    return [arr[i:i+k] for i in range(0,len(arr),k)]

class blue :
    def __init__(self) :
        self.b_p=0
    def blue_up(self) :
        self.b_p +=1
    def blue_return(self) :
        return self.b_p
class white :
    def __init__(self) :
        self.w_p = 0
    def white_up(self) :
        self.w_p +=1
    def white_return(self) :
        return self.w_p

def pooling(arr,num) :
    if len(arr) == 1:
        if arr == [[1]] :
            return bl.blue_up()
        else :
            return wh.white_up()
    else :
        arx = sum(arr,[])
        if max(arx) == min(arx) :
            if max(arx) ==1 :
                return bl.blue_up()
            else :
                return wh.white_up()
        else :
            pool_arr = [0]*num
            pooling_arr=[ [[],[]] for _ in range(2) ]
            for i in range(num) :
                pool_arr[i] = list_chunk(arr[i],num//2)
            for i in range(0,num,num//2) :
                for j in range(0,2) :
                    for k in range(i,i+num//2) :
                        if i ==0 :
                            pooling_arr[0][j].append(pool_arr[k][j])
                        else :
                            pooling_arr[1][j].append(pool_arr[k][j])
            for i in range(0,2) :
                for j in range(0,2) :
                    pooling(pooling_arr[i][j],len(pooling_arr[i][j]))
        
n=int(input())
arr=[list(map(int,input().split())) for _ in range(n)]
bl = blue()
wh = white()
pooling(arr,len(arr))

ans1 = wh.white_return()
ans2 = bl.blue_return()
print(ans1)
print(ans2)