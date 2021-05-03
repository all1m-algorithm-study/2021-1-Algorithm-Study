A =int(input())

for _ in range(A):
    C = int(input())

    Quarter = C//25
    C = C%25
    Dime = C//10
    C = C%10
    Nickel = C//5
    Penny = C%5

    print(Quarter, Dime, Nickel, Penny)