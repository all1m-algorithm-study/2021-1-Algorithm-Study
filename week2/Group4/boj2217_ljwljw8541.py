N = int(input())
R = [int(input())for i in range(N)]
Weight = []
for i in range(N):
    a = min(R)
    Weight.append(len(R)*a)
    R.remove(a)
print(max(Weight))