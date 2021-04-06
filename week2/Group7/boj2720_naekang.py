import sys

T = int(sys.stdin.readline())

for i in range(T):
    money = int(sys.stdin.readline())
    q = money // 25
    money %= 25
    d = money // 10
    money %= 10
    n = money // 5
    money %= 5
    p = money
    print(q, d, n, p)
