def main():
    _ = int(input())
    w_list = sorted(list(map(int, input().split())))

    cur_sum = 0
    for w in w_list:
        if w > cur_sum+1:  # 이전 인덱스까지의 합계+1보다 추의 무게가 크면 합과 추의 무게 사이에 잴수 없는 무게가 생김
            print(cur_sum+1)
            return
        cur_sum += w

    print(cur_sum+1)


if __name__ == "__main__":
    main()
