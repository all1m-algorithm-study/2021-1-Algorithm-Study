nn=int(input())
result =0
for i in range(1, nn+1):
    a=[int(j) for j in str(i)]
    result = i +sum(a)
    if result ==nn :
        print(i)
        break
    if i == nn :
        print(0)