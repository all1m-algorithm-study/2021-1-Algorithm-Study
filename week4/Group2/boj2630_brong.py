len_square = int(input())
paper = [list(map(int,input().split())) for i in range(len_square)]

def sum_arr (arr) :
    sum = 0
    for i in range (len(arr)):
        for j in range (len(arr)):
            sum += arr[i][j]
    return sum

def colored_paper (arr, white , blue):
    group1,group2,group3,group4 = [],[],[],[]

    if sum_arr(arr)==len(arr)**2 or sum_arr(arr)==0:
        return white, blue
    else :
        for i in range(len(arr)//2):
            group1.append(arr[i][:len(arr)//2])
            group2.append(arr[i][len(arr)//2:])
            group3.append(arr[i+len(arr)//2][:len(arr)//2])
            group4.append(arr[i+len(arr)//2][len(arr)//2:])
            return paper_array(group1), paper_array(group2), paper_array(group3), paper_array(group4)

def paper_array (arr):
    white = 0 ; blue = 0
    if sum_arr(arr) == len(arr)**2:
        blue += 1
        return colored_paper (arr, white, blue)
    elif sum_arr(arr) == 0 :
        white += 1 
        return colored_paper (arr, white, blue)
    else: 
        return colored_paper(arr, white, blue)

print(colored_paper(paper,0,0))

#다 못풀었어요......

 



