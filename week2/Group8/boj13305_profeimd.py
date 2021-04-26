n = int(input())
distance = list(map(int, input().split()))
price =  list(map(int, input().split()))

cost = distance[0]*price[0]
min_price = price[0]
distance_accumul = 0

for i in range(1, n-1) : 
    if price[i] < min_price : 
        cost += (min_price)*(distance_accumul)
        min_price = price[i]
        distance_accumul = distance[i]
    else : 
        distance_accumul += distance[i]

    if i == n-2 : 
        cost += (min_price)*(distance_accumul)

print(cost)