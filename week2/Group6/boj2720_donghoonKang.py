N = int(input())
cases = [int(input()) for _ in range(N)]

for i in cases:
    quarter = i // 25
    dime = (i - quarter*25) // 10
    nikel = (i - quarter*25 - dime*10) // 5
    penny = i - quarter*25 - dime*10 - nikel*5
    print('%d %d %d %d' % (quarter, dime, nikel, penny))
