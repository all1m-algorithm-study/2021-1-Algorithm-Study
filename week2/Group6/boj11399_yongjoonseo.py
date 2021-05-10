# ATM 1대, N명의 사람들 (1번부터 시작)
# i번 사람이 걸리는 시간 Pi분

# 출력: 인출하는데 필요한 시간의 합의 최솟값

# 가장 짧게 걸리는 사람부터 돈을 인출한다.

def solution(N):
    P = list(map(int, input().split()))
    P.sort()
    lst = [0] * N
    lst[0] = P[0]
    for i in range(1, N):
        lst[i] = lst[i-1] + P[i]
    print(sum(lst))

if __name__ == '__main__':
    solution(int(input()))