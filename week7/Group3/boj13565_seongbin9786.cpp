#include <stdio.h>
#include <stack>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int main()
{
    int i, j, M, N;
    stack<pair<int, int>> S;
    scanf("%d %d", &M, &N);
    char tmp[N + 1];
    bool map[M + 1][N + 1] = {0};
    bool visited[M + 1][N + 1] = {0};
    for (i = 1; i <= M; i++)
    {
        scanf("%s", tmp);
        for (j = 1; j <= N; j++)
            map[i][j] = tmp[j - 1] == '0' ? 1 : 0; // 0 이어야 전류가 통한다고 한다.
    }
    for (i = 1; i <= N; i++)
    {
        if (!map[1][i])
            continue;
        S.push(make_pair(1, i)); // [y,x]
        while (S.size() > 0)
        {
            int x, y, nx, ny;
            y = S.top().first;
            x = S.top().second;
            S.pop();
            visited[y][x] = true;
            if (y == M) // 바닥에 닿음.
            {
                printf("YES\n");
                return 0;
            }
            for (j = 0; j < 4; j++)
            {
                nx = x + dx[j];
                ny = y + dy[j];
                if (nx < 1 || nx > N || ny < 1 || ny > M)
                    continue;
                if (visited[ny][nx])
                    continue;
                if (!map[ny][nx])
                    continue;
                S.push(make_pair(ny, nx));
            }
        }
    }
    printf("NO\n");
    return 0;
}
