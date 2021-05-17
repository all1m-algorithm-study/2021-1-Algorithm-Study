n = int(input())

def pass_que(que):
    que.append(que.pop(0))

for i in range(n):
    cnt = 1
    length, target = map(int, input().split())
    ipt_que = list(map(int, input().split()))
    idx_que = list(map(str, range(1, length+1)))
    
    target = idx_que[target]
    
    while ipt_que != []:
        if ipt_que[0] == max(ipt_que) and idx_que[0] == target:
            break
        elif ipt_que[0] == max(ipt_que)  and idx_que[0] != target:
            cnt += 1
            ipt_que.pop(0)
            idx_que.pop(0)
        else:
            pass_que(ipt_que)
            pass_que(idx_que)
    print(cnt)
