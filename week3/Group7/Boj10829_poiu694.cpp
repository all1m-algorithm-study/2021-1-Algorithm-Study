#include <iostream>
#include <string>

using namespace std;

long long N;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve() {
    cin >> N;

    string answer = "";
    while (N != 0) {
        answer = to_string(N % 2) + answer;
        N = N / 2;
    }

    cout << answer;
}

int main() {
    fastIO();
    solve();
}