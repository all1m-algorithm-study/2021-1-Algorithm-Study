N = int(input())
print_num = 0
for i in range(1, N+1):
    div_num = list(map(int, str(i)))
    sum_num = i + sum(div_num)
    if sum_num == N:
        print_num = i
        break
print(print_num)