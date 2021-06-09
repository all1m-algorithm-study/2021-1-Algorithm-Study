#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int map[26][26];
bool visited[26][26] = {
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

int bfs(int i, int j, int N)
{
    queue<pair<int, int> > q;
    q.push({i, j});
    visited[i][j] = true;

    int cnt = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            {
                continue;
            }

            if (map[nx][ny] == 1 && !visited[nx][ny])
            {
                visited[nx][ny] = true;
                cnt++;
                q.push({nx, ny});
            }
        }
    }
    return cnt;
}

void solve()
{
    int N;
    cin >> N;

    string str;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        for (int j = 0; j < str.length(); j++)
        {
            map[i][j] = str[j] - '0';
        }
    }

    int cnt = 0;
    vector<int> list;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == 1 && !visited[i][j])
            {
                int temp = bfs(i, j, N);
                cnt++;
                list.push_back(temp);
            }
        }
    }

    sort(list.begin(), list.end());

    cout << cnt << '\n';
    for (int i = 0; i < list.size(); i++)
    {
        cout << list[i] << '\n';
    }
}

int main()
{
    fastIO();
    solve();
}
