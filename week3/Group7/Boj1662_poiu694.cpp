#include <iostream>
#include <stack>
#include <vector>

using namespace std;

string target;
bool visited[51];

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input()
{
    cin >> target;
}

// stack쓰다가 메모리초과................
// 그냥 넘겨주는 형식으로 해서 메모리를 줄이장
int dfs(string &target, int idx)
{
    int cnt = 0;

    for (int i = idx; i < target.size(); i++)
    {
        if (target[i] == '(' && !visited[i])
        {
            visited[i] = true;
            int rep = target[i - 1] - '0';
            cnt--;
            cnt += rep * dfs(target, i + 1);
        }
        else if (target[i] == ')' && !visited[i])
        {
            visited[i] = true;
            return cnt;
        }
        else if (!visited[i])
        {
            visited[i] = true;
            cnt++;
        }
    }

    return cnt;
}

void solve()
{
    cout << dfs(target, 0);
}

int main()
{
    fastIO();
    input();
    solve();
}