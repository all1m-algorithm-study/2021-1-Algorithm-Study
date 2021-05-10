#boj11728_ljwljw8541

#정렬이 되있으므로 젤앞에꺼 비교해서 작은수를 추가한다.. 계속 반복.
#한쪽 배열의 크기가 0이되면 나머지를 그냥 쭉넣으면 됨.
#둘다 크기가 0되면 출력
import sys
input = sys.stdin.readline

len_A,len_B =(map(int,input().split()))
A = list(map(int, input().split()))
B = list(map(int, input().split()))

def sort(A,B,sorted):
    m = 0 # m은 A의 탐색 인덱스
    n = 0 # n은 B의 탐색 인덱스
    global len_A
    global len_B
    while m < len_A and n < len_B:
        if A[m] >= B[n]:
            sorted.append(B[n])
            n += 1
        else:
            sorted.append(A[m])  
            m += 1

    if m == len_A:
        while n < len_B:
            sorted.append(B[n])
            n += 1
    elif n == len_B:
        while m < len_A:
            sorted.append(A[m])
            m += 1
        
    print(*sorted)
sort(A,B,[])