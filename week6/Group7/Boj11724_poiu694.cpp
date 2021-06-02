#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[1001];
bool visited[1001];

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void dfs(int node)
{
    visited[node] = true;

    for (int i = 0; i < graph[node].size(); i++)
    {
        int nextNode = graph[node][i];

        if (!visited[nextNode])
        {
            dfs(nextNode);
        }
    }
}

int whoIsNext(int N)
{
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            return i;
        }
    }
    return -1;
}

void solve()
{
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int nextNode, cnt = 0;
    bool flag = false;
    while (true)
    {
        nextNode = whoIsNext(N);
        if (nextNode == -1)
        {
            cout << cnt;
            break;
        }

        cnt++;
        dfs(nextNode);
    }
}

int main()
{
    fastIO();
    solve();
}