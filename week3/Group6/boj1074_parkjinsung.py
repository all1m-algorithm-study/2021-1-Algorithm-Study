n, r, c = map(int, input().split())

def find_index(n, row, col, start_num):
    length = int((2**n)/2)
    if n == 1:
        if row == 0 and col == 0:
            return start_num
        elif row == 0 and col == 1:
            return start_num + 1
        elif row == 1 and col == 0:
            return start_num + 2
        elif row == 1 and col == 1:
            return start_num + 3
    elif n > 1:
        if row < length:
            if col < length: # 0, 0
                start_num = start_num
                return find_index(n-1, row, col, start_num)  
            else:            # 0, 1
                start_num = start_num + ( 2**(n-1) * (2**(n-1)) )*1
                return find_index(n-1, row, col - int(length), start_num)       
        else:                
            if col < length: # 1, 0
                start_num = start_num + ( 2**(n-1) * (2**(n-1)) )*2
                return find_index(n-1, row - int(length), col, start_num)      
            else:            # 1, 1
                start_num = start_num + ( 2**(n-1) * (2**(n-1)) )*3  
                return find_index(n-1, row - int(length), col - int(length), start_num)

print(find_index(n, r, c, 0))
