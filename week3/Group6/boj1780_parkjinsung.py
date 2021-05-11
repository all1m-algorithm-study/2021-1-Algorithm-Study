n = int(input())
paper = []
for i in range(n):
    sliced_paper = list(map(int, input().split()))
    paper.append(sliced_paper)

def check_paper(paper, n):
    p_one_flag = 0
    zero_flag = 0
    m_one_flag = 0
    for i in range(n):
        for j in range(n):
            if paper[i][j] == 1:
                p_one_flag = 10
            elif paper[i][j] == 0:
                zero_flag = 10
            elif paper[i][j] == -1:
                m_one_flag = 10
            if (p_one_flag + zero_flag + m_one_flag) != 10:
                return 2
    if p_one_flag == 10:
        return 1
    elif zero_flag == 10:
        return 0
    elif m_one_flag == 10:
        return -1

def slice_paper(paper, n, r, c):
    sliced_num = int(n/3)
    sliced_paper = []
    for i in range(r*sliced_num, r*sliced_num + sliced_num):
        temp = []
        for j in range(c*sliced_num, c*sliced_num + sliced_num):
            temp.append(paper[i][j])
        sliced_paper.append(temp)
        temp = []
    return sliced_paper
    

def count_paper(paper, n):
    global cnt_p_one
    global cnt_zero
    global cnt_m_one
    if check_paper(paper, n) == 2:
        for i in range(3):
            for j in range(3):
                count_paper(slice_paper(paper, n, i, j), int(n/3))

        pass
    elif check_paper(paper, n) == 1:
        cnt_p_one += 1
    elif check_paper(paper, n) == 0:
        cnt_zero += 1 
    elif check_paper(paper, n) == -1:
        cnt_m_one += 1

cnt_p_one = 0
cnt_zero = 0
cnt_m_one = 0
count_paper(paper, n)
print(cnt_m_one, cnt_zero, cnt_p_one, sep = "\n")
