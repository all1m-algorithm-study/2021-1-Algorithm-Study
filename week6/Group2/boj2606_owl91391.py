import sys
input = sys.stdin.readline

class plus() :
    def __init__(self) :
        self.point=0
    def p_up(self) :
        self.point +=1
    def p_return(self) :
        return self.point


def virus (com_num,num,lis) :
    if com_num[num-1] == [] :
        return 
    else :
        for i in range(len(com_num[num-1])-1,-1,-1) :
            out =0
            for j in range(len(lis)) :
                if com_num[num-1][i] == lis[j] :
                    out = 1
            if out == 0 :
                po.p_up()
                t=num
                a = com_num[t-1][i]
                com_num[t-1].pop()
                lis.append(a)
                virus(com_num,a,lis)
            

N = int(input())
cnt = int(input())
relation = [list(map(int,input().split())) for _ in range(cnt)]
sor_rel = [[] for _ in range(N)]

for j in range(cnt) :
    sor_rel[relation[j][0]-1].append(relation[j][1])
    sor_rel[relation[j][1]-1].append(relation[j][0])
po=plus()
lis = [1]
virus(sor_rel,1,lis)
ans = po.p_return()
print(ans)