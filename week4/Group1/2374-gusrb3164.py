def main():
    n = int(input())
    A_height = []
    result = 0
    stack = []
    for _ in range(n):
        A_height.append(int(input()))
    for i in range(n):
        if not stack:
            stack.append(A_height[i])
        else:
            min_h = A_height[i]
            while stack and stack[-1] <= A_height[i]:
                pop_h = stack.pop(-1)
                min_h = min(pop_h, min_h)
            result += A_height[i]-min_h
            stack.append(A_height[i])

    if len(stack) > 1:
        result += (stack[0]-stack[-1])
    print(result)


if __name__ == "__main__":
    main()
