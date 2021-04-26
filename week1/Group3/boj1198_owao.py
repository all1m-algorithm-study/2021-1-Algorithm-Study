from math import *

def area(p1,p2,p3): #선택된 점 세개
    #신발끈 공식
    return abs(0.5*(p1[0]*p2[1]+p2[0]*p3[1]+p3[0]*p1[1]-p2[0]*p1[1]-p3[0]*p2[1]-p1[0]*p3[1]))


a=int(input()) #볼록 다각형의 점의 수
xy=[]
for i in range(a):
    p,q=map(int, input().split())
    xy.append([p,q]) #좌표 형태로 리스트에 저장


#xy는 들어온 좌표를 [[좌표1x,y],[좌표2x,y]....] 식으로 저장하고 있음
#즉 len(xy)가 들어온 좌표의 개수=a

A=0 #가장 큰 넓이
for i in range(a-2):
    for j in range(i+1,a-1):
        for k in range(j+1,a):
            p1=xy[i] #첫번째 좌표가 [x,y] 형태로 저장
            p2=xy[j]
            p3=xy[k]
            T=area(p1,p2,p3) #세 좌표로 넓이를 구함
            if T>A:
                A=T

print(A) #가장 큰 넓이 출력으로 종료
