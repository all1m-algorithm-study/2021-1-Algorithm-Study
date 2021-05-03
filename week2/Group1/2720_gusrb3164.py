def main():
    t_case = int(input())
    for _ in range(t_case):
        money = int(input())
        quarter = money//25
        money %= 25
        dime = money//10
        money %= 10
        nickel = money//5
        penny = money % 5
        print(quarter, dime, nickel, penny)


if __name__ == "__main__":
    main()
