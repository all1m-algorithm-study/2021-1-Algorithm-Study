# 왼쪽에서 정수 만큼 떨어진 거리에 물이 샌다
# 길이가 L인 테이프가 무한개 있다.
# 물을 막을 때 그 위치의 좌우 0.5 만큼 간격을 줘야 한다

# 출력: 필요한 테이프의 최소 개수

# 체크할 조건
# 1 <= N, L <= 1000

# 최대한 왼쪽에 붙여서 붙이면 최소 개수로 붙일 수 있다.

def solution(N, L):
    leaks = list(map(int, input().split()))
    leaks.sort()
    covered_num = cnt = 0

    for i in range(N):
        if leaks[i] > covered_num:
            cnt += 1
            covered_num = leaks[i] + L - 1
    
    print(cnt)

if __name__ == '__main__':
    solution(*map(int, input().split()))