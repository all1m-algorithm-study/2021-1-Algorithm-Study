from collections import deque

def printerQ (importance, number, goal, already):
    i = 0
    while i <= goal :
        if i < goal:
            if importance[0] == max(importance):
                already.append(importance.popleft())
                i += 1
            else:
                importance.append(importance.popleft())
                i += 1
        else:
            if importance[0] == max(importance):
                answer = len(already) +1
                return answer
            else:
                importance.append(importance.popleft())
                goal = len(importance) - 1
                number = len(importance)
                return printerQ(importance, number, goal,already)

N = int(input())        
i = 0
while i < N:
    number, goal = map(int,input().split())
    importance = deque(map(int,input().split()))
    already = []
    print(printerQ(importance,number, goal, already))
    i += 1

