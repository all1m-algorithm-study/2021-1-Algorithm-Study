n = int(input())
paper = []

for i in range(n):
    paper.append(list(map(int, input().split())))

def count_paper(paper):
    n = len(paper)
    count_white = 0
    count_blue = 0

    for i in range(n):
        for j in range(n):
            if paper[i][j] == 0:
                count_white += 1
            if paper[i][j] == 1:
                count_blue += 1

    if count_white == n*n:
        return 1, 0
    elif count_blue == n*n:
        return 0, 1
    else:
        if n == 2:
            return count_white, count_blue
        
        else:
            sliced_paper1 = []
            sliced_paper2 = []
            sliced_paper3 = []
            sliced_paper4 = []

            for i in range(n):
                if i < int(n/2):
                    sliced_paper1.append(paper[i][:int(n/2)])
                    sliced_paper2.append(paper[i][int(n/2):])
                if i >= int(n/2):
                    sliced_paper3.append(paper[i][:int(n/2)])
                    sliced_paper4.append(paper[i][int(n/2):])

            w1, b1 = count_paper(sliced_paper1)
            w2, b2 = count_paper(sliced_paper2)
            w3, b3 = count_paper(sliced_paper3)
            w4, b4 = count_paper(sliced_paper4)    

            return (w1 + w2 + w3 + w4), (b1 + b2 + b3 + b4)

white, blue = count_paper(paper)
print(white)
print(blue)
