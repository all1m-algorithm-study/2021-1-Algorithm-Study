import sys

a, b = map(int, input().split())
a_list = list(map(int, sys.stdin.readline().split()))
b_list = list(map(int, sys.stdin.readline().split()))
answer_list = a_list + b_list
answer = ' '.join(map(str, sorted(answer_list)))
print(answer)   

a, b = map(int, input().split())
a_list = list(map(int, input().split()))
b_list = list(map(int, input().split()))
answer_list = a_list + b_list
answer_list.sort()  
for i in answer_list:
    print(i, end=' ')