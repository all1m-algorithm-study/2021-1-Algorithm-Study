triangle = [n*(n+1)//2 for n in range(1, 46)]
eureka = [0] * 1001

#미리 1000이하의 모든 유레카 수를 구한다
for i in triangle:
    for j in triangle:
        for k in triangle:
            if i+j+k <= 1000:
                eureka[i+j+k] = 1

T = int(input())
for _ in range(T):
    print(eureka[int(input())])