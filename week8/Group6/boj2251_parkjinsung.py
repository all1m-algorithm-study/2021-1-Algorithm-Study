# boj2251
from collections import deque

def bfs(volume, result):
    q = deque([volume])
    result.append(volume)
    while q:
        curr = q.popleft()
        for pour_out, pour_in in case:
            temp_volume = list(curr) # deep copy
            p_o = curr[pour_out]
            p_i = curr[pour_in]

            if (p_o + p_i) > limit[pour_in]:
                temp_sum = p_i + p_o
                temp_volume[pour_out] = temp_sum - limit[pour_in]
                temp_volume[pour_in] = limit[pour_in]
            else:
                temp_volume[pour_out] = 0
                temp_volume[pour_in] = p_i + p_o
            
            if temp_volume in result:
                continue
            else:
                q.append(temp_volume)
                result.append(temp_volume)
    
a, b, c = map(int, input().split())
volume = [0, 0, c]
limit = [a, b, c]
case = [[0,1], [0,2], [1,0], [1,2], [2,0], [2,1]]
result = []

bfs(volume, result)

ans = set()
for i in result:
    if i[0] == 0:
        ans.add(i[2])
ans = list(ans)
ans.sort()
print(*ans)
