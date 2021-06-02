# n = int(input())
# m = int(input())

# edges = [[] for _ in range(n+1)]
# friends = []
# invited = [False for _ in range(n+1)]

# for _ in range(m):
#     a, b = map(int, input().split())
#     edges[a].append(b)
#     edges[b].append(a)

# for friend in edges[1]:
#     invited[friend] = True
#     for second_friend in edges[friend]:
#         invited[second_friend] = True

# cnt = 0
# for p in invited:
#     if p == True:
#         cnt += 1
# print(cnt)