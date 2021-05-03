import sys

a,b,c = map(int,sys.stdin.readline().split())

def pow(a,b):
    if b == 1:
        return a % c
    else:
        tmp = pow(a, b // 2)
        if b % 2 == 0:  # 짝수이면
            return tmp * tmp % c
        else:           # 홀수이면
            return tmp * tmp * a % c

print(pow(a, b))