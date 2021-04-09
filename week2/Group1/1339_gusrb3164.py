import collections


def main():
    N = int(input())
    word = collections.defaultdict(int)
    result = 0

    for _ in range(N):
        txt = str(input())
        for i in range(len(txt)):
            word[txt[len(txt)-i-1]] += 10**i
    for i, value in enumerate(sorted(word.values(), reverse=True)):
        result += value*(9-i)
    print(result)


if __name__ == "__main__":
    main()
