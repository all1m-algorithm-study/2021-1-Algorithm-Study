def binary(n):
    if n==1 :
        return '1'
    if n%2==1 :
        return binary(n//2) + '1'
    elif n%2==0 :
        return binary(n//2) + '0'

n = int(input())
answer = binary(n)
print(answer)