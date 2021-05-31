# n = int(input())
# target_a, target_b = map(int, input().split(' '))
# m = int(input())
# graph = [[] for _ in range(n)]

# parent_a = target_a
# parent_b = target_b
# for _ in range(m):
#     parent, child = map(int, input().split(' '))
#     graph[parent].append(child)
#     if child == target_a:
#         parent_a = parent
#     if child == target_b:
#         parent_b = parent
# print(graph)

# def dfs(path, curr, target):
#     path.append(curr)

#     for vb