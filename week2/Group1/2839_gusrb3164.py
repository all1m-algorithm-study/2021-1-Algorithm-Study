def main():
    N = int(input())
    leave = N % 5
    num5 = N//5

    while num5 > -1:
        if leave % 3 == 0:
            print(num5+leave//3)
            return
        leave += 5
        num5 -= 1
    print(-1)


if __name__ == "__main__":
    main()
