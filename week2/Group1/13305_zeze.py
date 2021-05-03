city_num = int(input())
road_length = list(map(int, input().split()))
price_gas = list(map(int, input().split()))

# 처음 도시에서 다음 도시의 길이만큼 꼭 주유 해야함
min_money = price_gas[0]
total_money = 0

for i in range(city_num - 1):
    if price_gas[i] < min_money:
        min_money = price_gas[i]
    total_money += min_money * road_length[i]

print(total_money)