'''
숫자야구
'''

def strike(n, question):
    rslt = 0

    if (n % 10 == question % 10): rslt += 1
    if ((n // 10) % 10 == (question // 10) % 10): rslt += 1
    if (n // 100 == question // 100): rslt += 1

    return rslt

def ball(n, question):
    arr1 = [n // 100, (n // 10) % 10, n % 10]
    arr2 = [question // 100, (question // 10) % 10, question % 10]
    rslt = 0

    if (arr1[0] == arr2[1] or arr1[0] == arr2[2]): rslt += 1
    if (arr1[1] == arr2[0] or arr1[1] == arr2[2]): rslt += 1
    if (arr1[2] == arr2[0] or arr1[2] == arr2[1]): rslt += 1

    return rslt

def guess_num_of_case():
    '''
    가능한 모든 숫자 리스트 생성
    주어진 볼, 스트라이크 조건과 생각하고 있는 숫자 비교
    가능하지 않은 경우 가능한 숫자 리스트에서 제외
    이하 반복 후 가능한 숫자 개수 출력
    '''
    arr = []
    a = 123 #1~9까지 서로 다른 세 숫자로 만들기때문에 최소 123부터 가능
    for i in range(889):
        a1 = a // 100 #100의자리
        a2 = (a // 10) % 10 #10의 자리
        a3 = a % 10 #1의자리리
        if a1 == 0 or a2 == 0 or a3 == 0: arr.append(-1) # 1~9까지 숫자 사용 조건 외 제외
        elif a1 == a2 or a1 == a3 or a2 == a3: arr.append(-1) #서로 다른 세 숫자 사용 조건 외 제외
        else: arr.append(a)

        a += 1

    # 스트라이크와 볼 개수 비교하여 다르면 제외
    n = int(input())
    for i in range(n):
        question, s, b = map(int, input().split())
        for j in range(889):
            if arr[j] != -1: #조건에 맞는 숫자일때
                S = strike(arr[j], question) #스트라이크 비교
                B = ball(arr[j], question) #볼 비교
                if s != S or b != B: arr[j] = -1 #두개 동시에 만족하지 않으면 제외

    rslt = 0
    for i in range(889):
        if arr[i] != -1: rslt += 1
    print(rslt)

    return 0


guess_num_of_case()