N=int(input())
answer=[]

def change(N):
    if N==1:
        print('1')
    elif N%2==0:
        return change(N//2)
        answer.append('0')
    else:
        return change(N//2)
        answer.append('1')
answer.reverse()
print(' '.join(answer))
#미완성 코드입니다ㅠㅠ 기한 내 제대로 된 코드를 제출하지 못해 죄송합니다. 다시 완성된 코드로 업로드하도록 하겠습니다.ㅠㅠ