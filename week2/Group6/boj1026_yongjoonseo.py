# 길이가 N인 정수 배열 A, B
# S = A[0]×B[0] + ... + A[N-1]×B[N-1]
# A의 수를 재배열하여 S값을 가장 작게 만든다

# 출력: S의 최솟값

# B의 큰 수 x A의 작은 수를 더한다.

def solution(N):
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    B.sort(reverse=True)
    A.sort()
    val = 0
    for i in range(N):
        val += A[i] * B[i]
    print(val)    

if __name__ == '__main__':
    solution(int(input()))