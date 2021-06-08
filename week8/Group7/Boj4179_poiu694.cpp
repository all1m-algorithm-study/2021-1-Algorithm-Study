#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

queue<pair<int, int> > fire;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool visited[1001][1001];
string map[1001];

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

// pq: moveCnt, isBreak? x, y
int bfs(int N, int M, int sx, int sy)
{
    queue<pair<int, int> > q;
    q.push({sx, sy});

    int ret = 0;
    while (!q.empty())
    {
        int fireSize = fire.size();
        for (int i = 0; i < fireSize; i++)
        {
            int x = fire.front().first;
            int y = fire.front().second;
            fire.pop();

            for (int j = 0; j < 4; j++)
            {
                int nx = x + dx[j];
                int ny = y + dy[j];

                if (nx >= 0 && ny >= 0 && nx < N && ny < M)
                {
                    if (map[nx][ny] == '.' || map[nx][ny] == 'J')
                    {
                        map[nx][ny] = 'F';
                        fire.push({nx, ny});
                    }
                }
            }
        }

        int qSize = q.size();
        for (int i = 0; i < qSize; i++)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == 0 || y == 0 || x == N - 1 || y == M - 1)
            {
                return ret + 1;
            }

            for (int j = 0; j < 4; j++)
            {
                int nx = x + dx[j];
                int ny = y + dy[j];

                if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                    continue;

                if (map[nx][ny] != '.' || visited[nx][ny])
                    continue;

                if (nx >= 0 && ny >= 0 && nx < N && ny < M)
                {
                    if (map[nx][ny] == '.' && !visited[nx][ny])
                    {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
        ret++;
    }

    return -1;
}

void solve()
{
    memset(visited, false, sizeof(visited));
    int N, M;
    cin >> N >> M;

    int sx, sy;
    for (int i = 0; i < N; i++)
    {
        cin >> map[i];
        for (int j = 0; j < map[i].length(); j++)
        {
            if (map[i][j] == 'J')
            {
                sx = i;
                sy = j;
            }

            if (map[i][j] == 'F')
            {
                fire.push({i, j});
            }
        }
    }

    int ans = bfs(N, M, sx, sy);
    if (ans == -1)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        cout << ans;
    }
}

int main()
{
    fastIO();
    solve();
}
