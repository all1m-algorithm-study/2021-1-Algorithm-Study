import heapq


def main():
    _, m = map(int, input().split())
    cards = list(map(int, input().split()))
    hq = []
    for card in cards:
        heapq.heappush(hq, card)
    for _ in range(m):
        num1 = heapq.heappop(hq)
        num2 = heapq.heappop(hq)
        heapq.heappush(hq, num1+num2)
        heapq.heappush(hq, num1+num2)
    print(sum(hq))


if __name__ == "__main__":
    main()
