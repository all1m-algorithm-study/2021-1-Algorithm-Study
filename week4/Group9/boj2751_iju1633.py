n = int(input())
array = []
for i in range(n):
    array += input()

array.sort()
for i in range(len(array)):
    print(array[i])