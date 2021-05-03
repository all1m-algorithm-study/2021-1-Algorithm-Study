N = int(input())
Length = list(map(int, input().split()))
Price = list(map(int, input().split()))
Money = 0 #총 비용
Stack = 0 #스택은 돈 안 내고 누적되는 거리
Cost =Price[0]
for i in range(N-1):
    Stack += Length[i]
    Money += Cost*Stack
    Stack = 0
    if Price[i+1]<=Cost:
        Cost = Price[i+1]
print(Money)