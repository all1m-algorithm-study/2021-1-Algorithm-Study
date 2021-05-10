#include <iostream>
#include <cmath>

using namespace std;

int N, R, C;
int temp = 0;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> N >> R >> C;
}

void cutArea(int i, int j, int num) {
    if (i == R && j == C) {
        cout << temp;
        return;
    }

    if (num == 1) {
        temp++;
        return;
    }

    if (!(R < i + num && R >= i && C < j + num && C >= j)) {
        temp += num * num;
        return;
    }

    for (int x = i; x < i + num; x += (num / 2)) {
        for (int y = j; y < j + num; y += (num / 2)) {
             cutArea(x, y, (num / 2));
        }
    }
}

void solve() {
    cutArea(0, 0, 1 << N);
}

int main() {
    fastIO();
    input();
    solve();
}