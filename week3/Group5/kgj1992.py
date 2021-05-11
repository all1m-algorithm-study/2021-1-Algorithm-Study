image=[]  
size=int(input())
image = [list(map(int, input())) for _ in range(size)]

def partial_sum(left,right,up,down,image):
    partial=0
    for i in range(up,down+1):
        for j in range(left,right+1):
            partial=partial+image[i-1][j-1]
    return partial
        
def zip(left,right,up,down,n):
    part=partial_sum(left,right,up,down,image)
    if n==1:
        print(image[up][left],end='')
        return
    elif part==(right-left+1)*(down-up+1):
        print(1,end='')
        return
    elif part==0:
        print(0,end='')
        return
    else:
        zip(left,right//2,up,down//2,n//4)
        zip(right//2+1,right,up,down//2,n//4)
        zip(left,right//2,down//2+1,down,n//4)
        zip(right//2+1,right,down//2+1,down,n//4)
    

zip(1,size,1,size,size*size)