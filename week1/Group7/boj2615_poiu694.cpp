#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int line = 19;
int lastX = -1; int lastY = -1; int _color = -1;
bool visited[20][20];
int map[20][20];
int moveX[8] = { 1,1,1,0,0,-1,-1,-1 };
int moveY[8] = { -1,0,1,1,-1,-1,0,1 };

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void is_omok(int color, int x, int y) {
    // 가로 체크
    int dx = x;
    int dy = y;
    int cnt = 0;
    while (map[dx][dy] == color && dy >= 0) {
        dy--; // 제일 왼쪽으로 가랏
    }
    while (map[dx][++dy] == color && dy <= line) {
        cnt++;
    }
    if (cnt == 5) {
        lastX = dx;
        lastY = dy - 5;
        _color = color;
        return;
    }

    //세로 체크
    dx = x;
    dy = y;
    cnt = 0;
    while (map[dx][dy] == color && dx >= 0) {
        dx--; // 제일 위로 가랏
    }
    while (map[++dx][dy] == color && dx <= line) {
        cnt++;
    }
    if (cnt == 5) {
        lastX = dx - 5;
        lastY = dy;
        _color = color;
        return;
    }

    // \ 방향 체크
    dx = x;
    dy = y;
    cnt = 0;
    while (map[dx][dy] == color && dx >= 0 && dy >= 0) {
        dx--; // 제일 왼쪽 위로 가랏
        dy--;
    }
    while (map[++dx][++dy] == color && dx <= line && dy <= line) {
        cnt++;
    }
    if (cnt == 5) {
        lastX = dx - 5;
        lastY = dy - 5;
        _color = color;
        return;
    }

    // / 방향 체크
    dx = x;
    dy = y;
    cnt = 0;
    while (map[dx][dy] == color && dx <= line && dy >= 0) {
        dx++; // 제일 왼쪽 아래로 가랏
        dy--;
    }
    while (map[--dx][++dy] == color && dx >= 0 && dy <= line) {
        cnt++;
    }
    if (cnt == 5) {
        lastX = dx + 5;
        lastY = dy - 5;
        _color = color;;
        return;
    }
    return; // 모두다 실패
}

void dfs(int cnt, int x, int y) {
    if (cnt == 5) {
        is_omok(map[x][y], x, y);
        return;
    }

    for (int i = 0; i < 8; i++) {
        int nx = x + moveX[i];
        int ny = y + moveY[i];

        if (nx >= 0 && ny >= 0 && nx <= line && ny <= line) {
            if (map[x][y] == map[nx][ny] && !visited[nx][ny]) {
                visited[nx][ny] = true;
                dfs(cnt + 1, nx, ny);
                visited[nx][ny] = false;
            }
        }
    }
}

void solve() {
    memset(visited, false, sizeof(visited));

    for (int i = 1; i <= line; i++) {
        for (int j = 1; j <= line; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 1; i <= line; i++) {
        for (int j = 1; j <= line; j++) {
            if (map[i][j] != 0) {
                visited[i][j] = true;
                dfs(1, i, j);
                visited[i][j] = false;
            }
        }
    }

    if (_color == -1) {
        cout << 0;
    }
    else {
        cout << _color << '\n' << lastX << " " << lastY;
    }
    return;
}

int main() {
    init();
    solve();
}
