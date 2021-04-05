'''
not yet solved
배열로 입력받기
1~N,M까지 한칸씩 돌아가면서 총 N*M개의 점에서 검사한다,
각 점에서는 그 점을 중심으로 십자가 채우기 검사
채울 수 있으면 채운 다음 채운 좌표 제외한 그래프 copy 생성
다시 십자기 채우기 검사
area1 * area2 최댓값 구해서 반환

'''
def check_could_put_a_cross(graph, y, x, n, m):

    if graph[y][x] == '.': return 0

    else:
        check_up = 1
        check_down = 1
        check_left = 1
        check_right = 1
        i = 1  # x,y,에서 한칸씩 늘려가면서 상하좌우로 검사하는데 사용되는 인자
        cross_area = 1
        while check_up*check_down*check_right*check_left:
            if y-i == 0 or graph[y-i][x] == '.': check_up = 0
            if y+i == n or graph[y+i][x] == '.': check_down = 0
            if x+i == m or graph[y][x+i] == '.': check_right = 0
            if x-i == 0 or graph[y][x-i] == '.':check_left = 0
            i += 1
            cross_area += 4

        return cross_area


def put_a_cross(cross_area, graph, y, x):
    if cross_area == 0:
        return graph

    else:
        num_draw_dot = 0
        cross_area -= 1
        while cross_area > 0:
            cross_area //= 4
            num_draw_dot += 1

        for i in range(1, num_draw_dot):
            graph[y+i][x].replace('#', '.')
            graph[y-i][x].replace('#', '.')
            graph[y][x+i].replace('#', '.')
            graph[y][x-i].replace('#', '.')

        for i in graph:
            print(i)

        return graph

def put_two_cross():
    
    n, m = map(int, input().split())
    graph = [input() for _ in range(n)] #그래프 받기
    max_area = 0
    
    for y in range(n):
        for x in range(m):
            graph_copy = graph
            area1 = check_could_put_a_cross(graph_copy, y, x, n, m)
            graph_copy = put_a_cross(area1, graph_copy, y, x)

            for y in range(n):
                for x in range(m):
                    area2 = check_could_put_a_cross(graph_copy, y, x, n, m)
                    max_area = max(max_area, area1*area2)
            print(max_area)

    return max_area

print(put_two_cross())