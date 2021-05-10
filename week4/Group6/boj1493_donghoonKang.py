import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

length, width, height = map(int, input().rstrip().split(" "))
n = int(input().rstrip())

cubes = [0] * 21
for _ in range(n):
    a, b = map(int, input().rstrip().split(" "))
    cubes[a] += b

total = 0
count = 0
for i in range(19, -1, -1):
    total <<= 3
    t = min(cubes[i], (length >> i)*(width >> i)*(height >> i) - total)
    total += t
    count += t

if(total == length*width*height):
    print(count)
else:
    print(-1)
"""
import sys
sys.setrecursionlimit(99999)

kinds = []
amounts = []


def fillBiggest(l, w, h):
    global kinds
    global amounts

    myChoice = 0
    for i in range(len(kinds)-1, -1, -1):
        if amounts[i] > 0:
            myChoice = i
            break

    side = 2 ** kinds[myChoice]
    if l < side or w < side or h < side:
        amounts[myChoice] = 0
        return fillBiggest(l, w, h)
    else:
        amounts[myChoice] -= 1

    oneRes, twoRes, threeRes = 0, 0, 0
    if l - side > 0 and side > 0 and h > 0:
        oneRes = fillBiggest(l - side, side, h)
    if w - side > 0 and l > 0 and h > 0:
        twoRes = fillBiggest(l, w-side, h)
    if h - side > 0 and side > 0:
        threeRes = fillBiggest(side, side, h-side)
    return 1 + oneRes + twoRes + threeRes


def main():
    global kinds
    global amounts
    length, width, height = map(int, input().split())
    N = int(input())
    for i in range(N):
        tmp1, tmp2 = map(int, input().split())
        kinds.append(tmp1)
        amounts.append(tmp2)

    BOX = length * width * height
    CUBES = 0
    for i in range(len(kinds)):
        mySide = 2**kinds[i]
        CUBES += mySide**3 * amounts[i]
    if BOX - CUBES <= 0:
        print(fillBiggest(length, width, height))
    else:
        print(-1)


if __name__ == "__main__":
    main()
"""
