a, b, c, d, e, f = map(int, input().split())

# y= (af-cd) / (ae-bd)

y = (a*f-c*d)/(a*e-b*d)

try:
    x = (c-b*y)/a
except:
    x = (f-e*y)/d

print(int(x), int(y))
