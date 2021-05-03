T = int(input())
arr = [int(input()) for i in range(T)]
def merong (x) :
    a = x//25 
    b = (x-(25*a)) // 10
    c = (x-(25*a)-(10*b)) // 5
    d = x-(25*a)-(10*b)-(5*c)
    print (a,b,c,d)
for i in range(T):
    merong (arr[i])
