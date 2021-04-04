n = int(input())
answer = [0] * n
strike = [0] * n
ball = [0] * n
count = 0

for i in range(0, n):
    answer[i], strike[i], ball[i] = map(int, input().split())

for i in range(1, 10):
    for j in range(1, 10):
        if(i == j): continue
        for k in range(1, 10):
            if(i == k or j == k): continue

            correct = True
            for l in range(0, n):
                s = 0
                b = 0
                x = [answer[l] // 100, (answer[l] // 10) % 10, answer[l] % 10]
                
                if(i == x[0]): s += 1
                if(j == x[1]): s += 1
                if(k == x[2]): s += 1
                if(i == x[1] or i == x[2]): b += 1
                if(j == x[0] or j == x[2]): b += 1
                if(k == x[0] or k == x[1]): b += 1
                if(s != strike[l] or b != ball[l]):
                    correct = False
                    break

            if(correct): count += 1

print(count)