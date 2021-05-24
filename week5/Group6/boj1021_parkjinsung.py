n, m = map(int, input().split())
pop_lst = list(map(int, input().split()))
que = list(range(1, n+1))

def que1(que):
    que.pop(0)
def que2(que):
    que.append(que.pop(0))
def que3(que):
    que.insert(0, que.pop())

cnt = 0

for i in range(m):
    while pop_lst[i] != que[0]:
        if que.index(pop_lst[i]) <= int(len(que)/2):
            cnt += 1
            que2(que)
        elif que.index(pop_lst[i]) > int(len(que)/2):
            cnt += 1
            que3(que)
    que.pop(0)

print(cnt)
