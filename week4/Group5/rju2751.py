import sys

def merge_sort(l, n):
    if(n <= 1): return l
    a = n // 2
    b = n - a
    l1 = merge_sort(l[:a], a)
    l2 = merge_sort(l[a:], b)
    return merge(l1, l2, a, b)

def merge(l1, l2, a, b):
    result = []
    i = 0
    j = 0
    while True:
        if(i >= a):
            result += l2[j:]
            break
        elif(j >= b):
            result += l1[i:]
            break
        if(l1[i] <= l2[j]):
            result.append(l1[i])
            i += 1
        else:
            result.append(l2[j])
            j += 1
    return result

n = int(sys.stdin.readline())
a = []
for i in range(0, n):
    a.append(int(sys.stdin.readline()))
a = merge_sort(a, n)
for i in a:
    print(i)