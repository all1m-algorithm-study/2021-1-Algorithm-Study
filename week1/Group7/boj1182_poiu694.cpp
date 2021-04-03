#include <iostream>

using namespace std;

int N, S;
int cnt = 0; // answer
int list[21];
bool visited[21];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        cin >> list[i];
    }
}

void dfs(int depth, int now) {
    if (depth == N) {
        return;
    }

    if(now + list[depth] == S){
        cnt++;
    }

    dfs(depth + 1, now);
    dfs(depth + 1, now + list[depth]);
}

void solve() {
    dfs(0, 0);

    cout << cnt;
}

int main() {
    init();
    input();
    solve();
}