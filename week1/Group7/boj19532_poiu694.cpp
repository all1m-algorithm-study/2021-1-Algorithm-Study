#include <iostream>
#include <cmath>

using namespace std;

int a, b, c, d, e, f;
int x, y;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> a >> b >> c >> d >> e >> f;
}

void solve() {
    //find y
    y = (a * f - c * d) / (a * e - b * d);
    x = (c * e - b * f) / (a * e - b * d);

    cout << x << " " << y;
}

int main() {
    init();
    input();
    solve();
}