N = int(input())
rope = []
max_w = 0

for i in range(N):
    rope.append(int(input()))

rope.sort(reverse=True)

for w in range(N):
    if max_w < rope[w] * (w+1):
        max_w = rope[w] * (w+1)

print(max_w)