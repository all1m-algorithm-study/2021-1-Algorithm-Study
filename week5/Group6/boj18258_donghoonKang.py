import sys


def solution():
    queue = [0] * 2000000
    front = rear = 0
    answer = []

    for string in sys.stdin.read().splitlines()[1:]:
        command = string[1]
        length = rear - front
        if command == "u":
            queue[rear] = int(string[5:])
            rear += 1
            continue
        elif command == "i":
            answer.append(length)
            continue
        elif command == "m":
            if length == 0:
                answer.append(1)
                continue
            else:
                answer.append(0)
                continue
        if length == 0:
            answer.append(-1)
            continue
        else:
            if command == "o":
                answer.append(queue[front])
                front += 1
                continue
            elif command == "r":
                answer.append(queue[front])
                continue
            elif command == "a":
                answer.append(queue[rear-1])
                continue

    sys.stdout.write('\n'.join(answer))


if __name__ == '__main__':
    solution()
