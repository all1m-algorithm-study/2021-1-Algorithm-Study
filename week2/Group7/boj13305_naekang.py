import sys

N = int(sys.stdin.readline())

# 거리 list 입력 받기 (N-1개)
dis = list(map(int, sys.stdin.readline().split()))
# 기름값 입력 받기 (N개)
oil_price = list(map(int, sys.stdin.readline().split()))

# 처음 출발할 때의 기름값[0]
start = oil_price[0]

# 총 기름값
sum = 0

# 오일 값의 리스트를 돌며 작아지는 경우 다시 가격 구하기
# 매번 작은 기름값을 저장해두고 사용
for i in range(len(dis)):
    if oil_price[i] < start:
        start = oil_price[i]
    sum += start * dis[i]

print(sum)
