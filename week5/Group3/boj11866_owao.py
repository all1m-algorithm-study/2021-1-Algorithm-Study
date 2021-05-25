#큐-리스트 사용

N, K=map(int, input().split()) #N명, 제거 단위 K
L=[] #인원수가 들어간 리스트

for i in range (N): #리스트에 인원 저장
    L.append(i+1)

a=0 #제거할 사람의 인덱스 번호
L2=[] #출력할 값 저장
for i in range(N):
    a=a+K-1
    if a>=len(L):
        a=a%len(L)
    L2.append(L.pop(a))
    
print(L2)
