#include <iostream>
#include <vector>

using namespace std;

int N, M;
bool visited[9];

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> N >> M;
}

void nCm(int num, int depth, vector<int> list) {
    if (depth == M) {
        for (int i = 0; i < list.size(); i++) {
            cout << list[i] << " ";
        }
        cout << '\n';
    }

    for (int i = num; i <= N; i++) {
        if (!visited[i]) {
            list.push_back(i);
            visited[i] = true;
            nCm(i, depth + 1, list);
            visited[i] = false;
            list.pop_back();
        }
    }
}

void solve() {
    for (int i = 1; i <= N; i++) {
        visited[i] = true;
        nCm(i, 1, { i });
        visited[i] = false;
    }
}

int main() {
    fastIO();
    input();
    solve();
}