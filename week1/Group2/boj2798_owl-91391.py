import sys
input = sys.stdin.readline
N,M=map(int,input().split())
card = [int(x) for x in input().split()]
result =0
for i in range(N) :
    for j in range(i+1,N) :
        for k in range(j+1,N) :
            sum_value = card[i] + card[j] +card[k]
            if sum_value <= M :
                result = max(result,sum_value)
print(result)