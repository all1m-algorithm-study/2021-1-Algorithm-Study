#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>

/*
	[Silver 1]
	단지 번호 붙이기

	정사각형 지도
	1은 집이 있는
	0은 집이 없는
	
	연결된 집의 모임인 단지를 정의하고 번호를 붙이려
	연결되었다 = 좌우, 혹은 아래위로 다른 집이 있는

	단지수
	집의 수를 오름차순으로 정렬하여 출력

	-----
	IDEA 잘 모르겠다.

	1. 일단 matrix에서 단지를 발견해야 한다.
	=> N*N <= 25*25 <= 5^4 = 625
	=> 그냥 브루트포스로 집이면서 visited 아닌 곳 가면 될듯

	2. 단지를 발견하는 경우 dfs/bfs로 탐색해서 모두 visited로 만들고, 개수를 종합한다.
	=> BFS를 쓰자. 훨씬 편할 것 같다.

	3. 단지 탐색이 종료된 경우 (1)로 돌아가서 이를 반복한다.
	=> 집 개수 배열의 단지 idx에 집개수를 삽입한다.

	4. 집 개수 배열을 오름차순 정렬하여 출력한다.

	---
	OutOfBounds.. why? ?? ??? ???? // 뭐지.. 무한히 틀리는 중이다;
    => rooms[] 배열의 크기가 N이 최대일거라고 근거 없이 생각했음...
*/

using namespace std;

bool matrix2667[26][26] = {0};
bool visited2667[26][26] = {0};
int n2667;

int bfs(int by, int bx)
{
    int pos_y[] = {0, 0, -1, 1};
    int pos_x[] = {1, -1, 0, 0};
    int size = 0, y, x, ny, nx;
    queue<pair<int, int>> q;
    q.push(make_pair(by, bx));
    while (!q.empty())
    {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        // 큐에 넣을 때 체크하지만 앞 대기열을 처리하면서 visited된 경우 있어서 필요함
        // 이런 부분은 BFS < DFS 인듯.
        if (visited2667[y][x])
            continue;

        visited2667[y][x] = true;
        size++;

        for (int i = 0; i < 4; i++)
        {
            ny = y + pos_y[i];
            nx = x + pos_x[i];
            if (nx < 1 || ny < 1 || nx > n2667 || ny > n2667)
                continue;
            if (matrix2667[ny][nx] && !visited2667[ny][nx])
                q.push(make_pair(ny, nx));
        }
    }
    return size;
}

// 익숙해서 i=1부터 시작했는데, 굳이 그럴 필요는 없는 문제이다.
int main()
{
    int i, j, label = 0;
    char buf[26] = {0};
    int rooms[625] = {0}; // idx=0은 나중에 출력할 때 생략하기

    cin >> n2667;
    for (i = 1; i <= n2667; i++)
    {
        scanf("%s", buf);
        for (j = 1; j <= n2667; j++)
            if (buf[j - 1] == '1')
                matrix2667[i][j] = true;
    }

    // 여기선 [y][x]로 굳이 할 필욘 없지만 헷갈리니까.
    for (i = 1; i <= n2667; i++)
        for (j = 1; j <= n2667; j++)
            if (matrix2667[j][i] && !visited2667[j][i])
                rooms[label++] = bfs(j, i);

    sort(rooms, rooms + label); // 오름차순이 기본이었던걸로

    printf("%d\n", label);
    for (i = 0; i < label; i++)
        printf("%d\n", rooms[i]);
    return 0;
}
