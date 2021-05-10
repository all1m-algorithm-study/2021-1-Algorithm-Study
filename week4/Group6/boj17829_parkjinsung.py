n = int(input())
data = []
for i in range(n):
    data.append(list(map(int, input().split())))

def ttt_pooling(data, n):
    if n == 2:
        temp_lst = []
        for i in range(2):
            for j in range(2):
                temp_lst.append(data[i][j])
        temp_lst.sort()
        return temp_lst[2]
    elif n != 2:
        temp_data = [[], []]
        pooled_data = []
        index = 0
        for i in range(0, n, 2):
            pooled_data.append([])
            for j in range(0, n, 2):
                temp_data[0].append(data[i][j])
                temp_data[0].append(data[i][j+1])                
                temp_data[1].append(data[i+1][j])                
                temp_data[1].append(data[i+1][j+1])                
                pooled_data[index].append(ttt_pooling(temp_data, 2))
                temp_data = [[], []]
            index += 1
        return ttt_pooling(pooled_data, int(n/2))
    
print(ttt_pooling(data, n))
