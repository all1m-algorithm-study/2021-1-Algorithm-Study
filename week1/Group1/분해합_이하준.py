N = int(input()) # N 받기
r = 0 # 범위값
def ten(M): # 가. 10^(자리수-1) 리턴하는 함수
    return 10**(len(str(M))-1)

def s(M): # 나. M의 각 자리수 합 구하는 함수
    if M<10:
        return M
    return M//ten(M) + s(M%(ten(M)))

for n in range(1,7): # 다. r 정하기
    if N<=(10**n)-1+9*n:
        r = n
        break

for M in range(N-9*r,N): # 라. 범위 내에서 9r회 완전탐색
    if N == M+s(M):
        print(M)
        break

if M==N-1: # 마. M 없을때 출력
    print(0)
