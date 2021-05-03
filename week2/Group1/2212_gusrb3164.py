def main():
    N = int(input())
    K = int(input())
    sensors = sorted(list(map(int, input().split())))
    distance = sensors[-1]-sensors[0]
    gaps = []
    for i in range(N-1):
        if sensors[i+1]-sensors[i] != 0:
            gaps.append(sensors[i+1]-sensors[i])
    gaps.sort()

    while len(gaps) and K > 1:
        distance -= gaps.pop(-1)
        K -= 1
    if len(gaps) == 0:
        print(0)
        return
    print(distance)


if __name__ == "__main__":
    main()
