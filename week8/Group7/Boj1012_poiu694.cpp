#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int map[51][51];
bool visited[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void bfs(int i, int j, int N, int M)
{
    queue<pair<int, int> > q;
    visited[i][j] = true;
    q.push({i, j});

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx > N || ny < 0 || ny > M)
            {
                continue;
            }
            if (map[nx][ny] == 0 || visited[nx][ny])
            {
                continue;
            }

            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
}

void solve()
{
    int T;
    cin >> T;
    while (T--)
    {
        memset(map, 0, sizeof(map));
        memset(visited, false, sizeof(visited));

        int N, M, K, a, b;
        cin >> N >> M >> K;

        for (int i = 0; i < K; i++)
        {
            cin >> a >> b;
            map[a][b] = 1;
        }

        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (!visited[i][j] && map[i][j] == 1)
                {
                    cnt++;
                    bfs(i, j, N, M);
                }
            }
        }

        cout << cnt << '\n';
    }
}

int main()
{
    fastIO();
    solve();
}
