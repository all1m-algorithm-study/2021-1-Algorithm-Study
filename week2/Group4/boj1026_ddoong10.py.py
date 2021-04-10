n = int(input())
a = [0]*n
b = [0]*n
answer = 0
z = 0
a = list(map(int,input().split()))
b = list(map(int,input().split()))
for z in range(n):
    answer = answer + min(a)*max(b)
    a.pop(a.index(min(a)))
    b.pop(b.index(max(b)))
print(answer)