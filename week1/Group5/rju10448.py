n = int(input())
t = [(i * (i + 1)) // 2 for i in range(1, 45)]

for i in range(0, n):
    case = int(input())
    answer = 0
    for j in range(0, 44):
        if(t[j] >= case): break
        for k in range(j, 44):
            for l in range(k, 44):
                if(t[j] + t[k] + t[l] == case):
                    answer = 1
                    break
            if(answer): break;
        if(answer): break;
    print(answer)
