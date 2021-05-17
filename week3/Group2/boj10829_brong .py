def binary(n) :
    answer = [1] 
    if n == 1 :
        return answer
    else:
        arr = [n%2]
        return binary(n//2) + arr
ekq = binary(int(input()))
print(''.join((str(i) for i in ekq)))