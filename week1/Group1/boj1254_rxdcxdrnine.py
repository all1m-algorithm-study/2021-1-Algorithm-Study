string = input()

for i in range(len(string)):
    tmp = string + string[:i][::-1]
    if tmp == tmp[::-1]:
        break

print(len(tmp))