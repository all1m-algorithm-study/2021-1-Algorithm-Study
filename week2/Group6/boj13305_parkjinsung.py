cityNum = int(input())
length = list(map(int, input().split()))
fee = list(map(int, input().split()))

tempFee = fee[0]
total = 0

for i in range(cityNum-1):
    if fee[i] < tempFee:
        tempFee = fee[i]
    total += tempFee*length[i]

print(total)
