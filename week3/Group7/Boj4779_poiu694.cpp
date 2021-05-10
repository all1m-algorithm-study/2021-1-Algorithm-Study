#include <iostream>
#include <cmath>

using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void Cantor(int idx, int num) {
    int temp = pow(3, num);

    if ((int)( idx / temp) == 1) { // idx / pow(3,num)은 double 반환
        cout << ' ';
    }
    else {
        if (num == 0) {
            if (idx % 3 != 1) {
                cout << '-';
            }
            else {
                cout << ' ';
            }
        }
        else {
            Cantor((int)(idx % temp), num - 1);
        }
    }
}

void solve() {
    int N;
    while (cin >> N) {
        if (N == 0) {
            cout << '-' << endl;
            continue;
        }

        for (int i = 0; i < pow(3, N); i++) {
            Cantor(i, N - 1);
        }

        cout << '\n';
    }
}

int main() {
    fastIO();
    solve();
}