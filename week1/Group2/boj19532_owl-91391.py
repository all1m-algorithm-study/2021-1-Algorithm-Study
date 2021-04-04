import sys
input = sys.stdin.readline
a,b,c,d,e,f = map(int,input().split())
y = (c*d - f*a)//(b*d - e*a)
x = (c*e - f*b)//(a*e - d*b)
print(x, y ,sep=' ')