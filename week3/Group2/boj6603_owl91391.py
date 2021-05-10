def comb (st,se) :
    if len(se) == 6: 
        print(*se)
    elif st <=(len(s)-1) : 
        se.append(s[st]) 
        comb(st+1,se) 
        se.pop() 
        comb(st+1,se)
while True :
    s = list(map(int,input().split()))
    if s == [0] : # 0 입력시 종료
        break
    else :
        del s[0] # 0을 입력하지 않은 경우, s[0]은 본문의 k개의 수 이므로 편의상 제거         
    comb(0,[]) #조합 함수
    print('')