#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int cur, cnt;

    Node(int cur, int cnt)
    {
        this->cur = cur;
        this->cnt = cnt;
    }
};

int main()
{
    int i, m, n, x, y, src, dest, cnt, cur;
    cin >> n >> src >> dest >> m;
    bool visited[n + 1] = {0};
    bool matrix[n + 1][n + 1] = {0};
    queue<Node> Q;

    for (i = 0; i < m; i++)
    {
        cin >> x >> y;
        matrix[x][y] = 1;
        matrix[y][x] = 1;
    }

    Q.push(Node(src, 0));
    while (!Q.empty())
    {
        cur = Q.front().cur;
        cnt = Q.front().cnt;
        Q.pop();

        if (cur == dest)
        {
            cout << cnt << '\n';
            return 0;
        }

        visited[cur] = 1;
        for (int i = 1; i <= n; i++)
            if (matrix[cur][i] && !visited[i])
                Q.push(Node(i, cnt + 1));
    }
    cout << "-1\n";
    return 0;
}
