# 1. 각 동전의 갯수를 몫과 나머지 연산자를 통해 계산한다.
#
# 시간복잡도 = O(n)

n = int(input())

for _ in range(n):
    change = int(input())
    quarter = change // 25
    change %= 25
    dime = change // 10
    change %= 10
    nickel = change // 5
    change %= 5
    print("%d %d %d %d" % (quarter, dime, nickel, change))
