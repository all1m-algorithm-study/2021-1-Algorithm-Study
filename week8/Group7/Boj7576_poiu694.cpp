#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

queue<pair<int, pair<int, int> > > q;
int map[1001][1001];
bool visited[1001][1001] = {
    false,
};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int cntZero(int N, int M)
{
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 0)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int bfs(int N, int M)
{
    int zeroCnt = cntZero(N, M);

    int ret = -1;
    while (!q.empty())
    {
        int now = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        ret = now > ret ? now : ret;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            {
                continue;
            }
            if (visited[nx][ny])
            {
                continue;
            }

            if (map[nx][ny] == 0)
            {
                q.push({now + 1, {nx, ny}});
                map[nx][ny] = 1;
                visited[nx][ny] = true;
                zeroCnt--;
            }
        }
    }

    return zeroCnt > 0 ? -1 : ret;
}

void solve()
{
    int N, M;
    cin >> M >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 1)
            {
                visited[i][j] = true;
                q.push({0, {i, j}});
            }
        }
    }

    cout << bfs(N, M);
}

int main()
{
    fastIO();
    solve();
}
