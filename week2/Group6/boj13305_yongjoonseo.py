# N개의 도시, 일직선 도로 위에 있다.
# 제일 왼쪽 -> 제일 오른쪽 도시로 이동
# 1km마다 1리터의 기름 사용

# 출력: 제일 왼쪽 -> 제일 오른쪽 도시로 가는 최소 비용

# 체크할 조건
# 2 <= N <= 100000 (도시의 개수)
# 1 <= 제일 왼쪽 - 제일 오른쪽 도시까지 거리 <= 10억
# 1 <= 리터당 가격 <= 10억

# 왼쪽에서 오른쪽으로 도시를 체크하면서
# 리터당 가격이 작아지는 도시 부터 다음 그런 지점까지 거리 만큼의 기름을 넣는다.

def solution(N):
    roads = list(map(int, input().split()))
    prices = list(map(int, input().split()))
    val = 0
    min_price = prices[0]
    
    temp_dist = 0
    for i in range(N-1):
        if min_price > prices[i]:
            val += temp_dist * min_price
            min_price = prices[i]
            temp_dist = roads[i]
        else:
            temp_dist += roads[i]
    val += temp_dist * min_price
    print(val)

if __name__ == '__main__':
    solution(int(input()))