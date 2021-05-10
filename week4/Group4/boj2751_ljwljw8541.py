#boj2751_ljwljw8541

import sys
input = sys.stdin.readline

N = int(input())
notsort = list(int(input()) for _ in range(N))#정렬안된거

def merge(A,B,sorted):
    m = 0 # m은 A의 탐색 인덱스
    n = 0 # n은 B의 탐색 인덱스
    len_A = len(A)
    len_B = len(B)
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
        
    return sorted

def mergesort(list):
    if len(list) <= 1:
        return list
    mid = len(list)//2
    left = list[:mid]
    right = list[mid:]
    left = mergesort(left)
    right = mergesort(right)
    return merge(left,right,[])
    
K = mergesort(notsort)
for i in K:
    print(i)