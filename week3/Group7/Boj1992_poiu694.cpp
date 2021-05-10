#include <iostream>
#include <cmath>

using namespace std;

int N;
int map[65][65];

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> N;

    string str;
    for (int i = 0; i < N; i++) {
        cin >> str; // 입력받는 시간을 줄이기 위해 1줄씩 입력
        for (int j = 0; j < str.length(); j++) {
            map[i][j] = str[j] - '0';
        }
    }
}

// 영역 형성이 되는가?
bool is_Area(int i, int j, int size, int color) {
    for (int x = i; x < i + size; x++) {
        for (int y = j; y < j + size; y++) {
            if (map[x][y] != color) {
                return false;
            }
        }
    }

    return true;
}

void cutArea(int i, int j, int size) {
    if (is_Area(i, j, size, map[i][j])) {
        cout << map[i][j];
        return;
    }

    cout << '(';
    for (int x = i; x < i + size; x += (size / 2)) {
        for (int y = j; y < j + size; y += (size / 2)) {
            cutArea(x, y, (size / 2));
        }
    }
    cout << ')';
}

void solve() {
    cutArea(0, 0, N);
}

int main() {
    fastIO();
    input();
    solve();
}