N = int(input())

found = 0
for M in range(1, N):
    temp = M
    s = temp
    
    while temp > 0:
        s += temp % 10
        temp = int(temp / 10)
        
    if s == N:
        print(M)
        found = 1
        break

if not found:
    print(0)