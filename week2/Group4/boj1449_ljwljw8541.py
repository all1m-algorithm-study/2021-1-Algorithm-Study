N,L = map(int, (input().split()))
x = list(map(int,input().split()))

def how_many(R):
    R.sort()
    a = 1 #테이프 개수
    A = R[0] #A값은  빵꾸의 위치 , 처음 위치로 초기화 함.
    for i in range(1,len(R)):
        if R[i] <= A-1+L:
            continue #1개의 테이프로 커버할 수 있다면 넘어가야지!
        else: 
            A = R[i] # 못 커버하면 새로 테이프를 써야지!
            a += 1
    return a
print(how_many(x))