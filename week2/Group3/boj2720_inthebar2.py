def change(C):    
    temp = C
    q = int(temp / 25)
    temp %= 25
    d = int(temp / 10)
    temp %= 10
    n = int(temp / 5)
    temp %= 5
    p = temp
    print(q, d, n, p)
    

N = int(input())
for i in range(N):
    change(int(input()))
