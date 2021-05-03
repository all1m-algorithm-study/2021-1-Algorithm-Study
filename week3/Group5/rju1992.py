def quadTree(data, n):
    c = check(data)
    if(c != ""):
        return c
    else:
        s = "("
        n = n // 2
        for i in range(0, 2):
            for j in range(0, 2):
                tmp = ""
                for k in range(0, n):
                    l = i * n * n * 2 + j * n + k * n * 2
                    tmp += data[l:l + n]
                s += quadTree(tmp, n)
        s += ")"
        return s

def check(data):
    d = data[0]
    for i in data:
        if(d != i): return ""
    return d

n = int(input())
data = ""

for i in range(0, n):
    data += input()

print(quadTree(data, n))