T = int(input())

for i in range(T):
    C = int(input())
    Quarter = 0; Dime = 0; Nickel = 0; Penny = 0
    while True:
        if C / 25 >= 1:
            Quarter += 1; C -= 25
        else: break
    while True:
        if C / 10 >= 1:
            Dime += 1; C -= 10
        else: break
    while True:
        if C / 5 >= 1:
            Nickel += 1; C -= 5
        else: break
    while True:
        if C / 1 >= 1:
            Penny += 1; C -= 1
        else: break
    print(Quarter, Dime, Nickel, Penny)