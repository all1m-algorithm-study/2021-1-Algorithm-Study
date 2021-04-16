#include <iostream>

using namespace std;

int A, B, C;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> A >> B >> C;
}

long long power(int A, int B) {
    if (B == 0) {
        return 1;
    }
    else if (B == 1) {
        return A;
    }
    else {
        if (B % 2 == 0) {
            long long t = power(A, B / 2);
            return t * t % C;
            // return power(A, B/2) * power(A, B/2) % C; -> 메모리 초과
        }
        else {
            return power(A, B-1) * A % C;
        }
    }
}

void solve() {
    int result = power(A % C, B);

    cout << result;
}

int main() {
    fastIO();
    input();
    solve();
}