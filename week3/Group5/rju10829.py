def binary(n):
    if(n == 0) : return ""
    return binary(n // 2) + str(n % 2) 

n = int(input())

print(binary(n))