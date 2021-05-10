N = int(input())
strike = 0
ball = 0
correct = 0
M = 0
l = []
for i in range(N):
    l.append(list(map(str,input().split())))
for i in range(100,1000):
    s=str(i)
    if s[0]==s[1] or s[1]==s[2] or s[0]==s[2] or '0' in s:
        continue
    correct = 0
    for j in range(N):
        strike = 0
        ball = 0
        for k in range(3):
            if str(i)[k] == l[j][0][k]:
                strike+=1
        for n in range(9):
            if str(i)[n%3] == l[j][0][n//3]:
                ball+=1
        ball=ball-strike
        if strike==int(l[j][1]) and ball==int(l[j][2]):
            correct+=1
    if correct==N:
        M+=1

print(M)
