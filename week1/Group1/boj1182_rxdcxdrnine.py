from itertools import combinations

n, s = list(map(int, input().split()))
nums = list(map(int, input().split()))

# graph = {}
# for i, num in enumerate(nums):
#     graph[num] = nums[i + 1:]
#
# partials = []
# for i in range(1, n + 1):
#     result = []
#
#     def recursive_dfs(v, depth, target, discovered):
#         discovered.append(v)
#         depth += 1
#
#         if depth == target:
#             result.append(discovered[:])
#         else:
#             for w in graph[v]:
#                 if w not in discovered:
#                     discovered = recursive_dfs(w, depth, target, discovered)
#                     discovered.pop()
#
#         return discovered[:]
#
#     for num in nums:
#         recursive_dfs(num, 0, i, [])
#
#     partials.extend(result)
#
# result = 0
# for partial in partials:
#     if sum(partial) == s:
#         result += 1

partials = []
for i in range(1, n + 1):
    partials.extend(list(combinations(nums, i)))

result = 0
for partial in partials:
    if sum(partial) == s:
        result += 1

print(result)