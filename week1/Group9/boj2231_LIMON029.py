def firstStep(N):
    arr = []
    exp = 10
    result=int(N)
    int_N = int(N)
    length = len(N)
    for i in range(length):
        arr.append(int_N % exp)
        result-=9
        int_N //= exp
    arr.reverse()
    return arr, result

def secondStep(N):
    arr = []
    exp = 10
    result=N
    length = len(str(N))
    for i in range(length):
        arr.append(N % exp)
        result+=arr[i]
        N //= exp
    return result
N = input()
none=True
arr, result=firstStep(N)
for i in range(9*len(N)):
    result+=1
    ans = secondStep(result)
    if ans==int(N):
        print(result)
        none=False
        break
if none:
    print(0)