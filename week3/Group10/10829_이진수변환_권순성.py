def f(num):
    if num<2:
        return str(num)
    return f(num//2)+str(num%2)
n=int(input().strip())
print(f(n))