Q = int(input())
for _ in range(Q):
    n, m = map(int,input().split())
    importance = list(map(int,input().split()))
    index = [0 for _ in range(n)]
    index[m] = 'point'
    cnt = 0
   
    while True :
        if importance[0] == max(importance):
            cnt +=1
            
            if index[0] == 'point':
                print(cnt)
                break
            else : 
                importance.pop(0)
                index.pop(0)
        else:
            importance.append(importance.pop(0))
            index.append(index.pop(0))