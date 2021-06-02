arr = []

size_a, size_b = map(int, input().split())

for _ in range(2):
    arr = arr+(list(map(int, input().split())))

print(' '.join(map(str,sorted(arr))))
