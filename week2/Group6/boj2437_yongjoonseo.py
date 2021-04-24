# 저울 양팔의 길이는 같다
# N개의 저울추

# 출력: 추를 사용하여 측정할 수 없는 양의 정수 중 최솟값

# 체크할 조건
# 1 <= N <= 1000
# 1 <= 추의 무게 <= 1000000

# 오름차순으로 추를 정렬
# n번째 수열을 an, n번째까지 누적합을 Sn
# Sn + 1 >= a(n+1)라면 n번째까지 셀 수 있다.
# i) n == 0
    # S(-1) + 1 >= a0
    # a0이 1인 경우 가능
# ii) n일때 만족한다고 가정 (Sn + 1 >= a(n+1))
    # S(n+1) = Sn + a(n+1)
    # 1 ~ Sn은 만족한다고 가정한 상태
    # Sn + 1 ~ S(n+1) 까지는 a(n+1) + (1~Sn 중 적절히 선택)해서 만들 수 있다.
    # Sn + 1 >= a(n+1)이 만족하는 한 1~Sn+1까지 셀 수 있다.
        # 만족하지 않는 순간 Sn+1이 최솟값

def solution(N):
    weights = sorted(list(map(int, input().split())))
    sumval = 0

    for i in range(N):
        if sumval + 1 >= weights[i]:
            sumval += weights[i]
        else:
            break
    print(sumval + 1)

if __name__ == '__main__':
    solution(int(input()))