#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int N, M;
char map[16][16];
bool visited[16][16];
vector<pair<int, pair<int,int>>> list;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> N >> M;

    string str;
    for (int i = 0; i < N; i++) {
        cin >> str;
        for (int j = 0; j < M; j++) {
            map[i][j] = str[j];
        }
    }
}

int dfs(int x, int y) {
    int size; // size0 -> 1, 1 -> 5, 2 -> 9, 3->13...
    
    int nx = x; // 북쪽으로 보내버리기
    int ny = y;
    while (map[nx][ny] == '#' && nx >= 0) {
        nx--;
    }

    int sx = x; // 남쪽으로 보내버리기
    int sy = y;
    while (map[sx][sy] == '#' && sx < N) {
        sx++;
    }

    int wx = x; // 서쪽으로 보내버리기
    int wy = y;
    while (map[wx][wy] == '#' && wy >= 0) {
        wy--;
    }

    int ex = x; // 동쪽으로 보내버리기
    int ey = y;
    while (map[ex][ey] == '#' && wy < M) {
        ey++;
    }

    size = min((x - nx), (sx - x));
    size = min(size, (y - wy));
    size = min(size, (ey - y));

    return (size-1) * 4 + 1;
}

bool visit_map(int size, int x, int y) {
    int len = (size - 1) / 4;

    visited[x][y] = true;

    for (int i = 1; i <= len; i++) {
        if (visited[x + i][y]) {
            return false;
        }
        if (visited[x - i][y]) {
            return false;
        }
        if (visited[x][y + i]) {
            return false;
        }
        if (visited[x][y - i]) {
            return false;
        }
        visited[x + i][y] = true;
        visited[x - i][y] = true;
        visited[x][y + i] = true;
        visited[x][y - i] = true;
    }

    return true;
}

void solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == '#') {
                list.push_back({ dfs(i, j), {i, j} });
            }
        } 
    }

    int maxArea = -1;
    for (int i = 0; i < list.size(); i++) {
        for (int j = i + 1; j < list.size(); j++) {
            memset(visited, false, sizeof(visited));

            if (list[i].first != 1) {
                int cnt = 0;
                while (list[i].first - cnt != 1) {
                    memset(visited, false, sizeof(visited));
                    
                    visit_map(list[i].first - cnt, list[i].second.first, list[i].second.second);
                    if (visit_map(list[j].first, list[j].second.first, list[j].second.second)) {
                        maxArea = max(maxArea, (dfs(list[i].second.first, list[i].second.second)-cnt) * dfs(list[j].second.first, list[j].second.second));
                    }

                    cnt += 4;
                }
            }
            else {
                visit_map(list[i].first, list[i].second.first, list[i].second.second);
                if (visit_map(list[j].first, list[j].second.first, list[j].second.second)) {
                    maxArea = max(maxArea, dfs(list[i].second.first, list[i].second.second) * dfs(list[j].second.first, list[j].second.second));
                }
            }
        }
    }

    cout << maxArea;
}

int main() {
    init();
    input();
    solve();
}