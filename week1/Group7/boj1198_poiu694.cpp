#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int N; // number of Dot
vector<pair<int, int>> dotList; // x&y List

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(1);
    cout << fixed;
}

void input() {
    cin >> N;

    int x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        dotList.push_back({ x, y });
    }
}

double calArea(int a, int b, int c, int d, int e, int f) {
    return abs((double) ( (a * d) + (c * f) + (e * b) ) - ( (c * b) + (e * d) + (a * f) ) ) / 2;
}

// Not cut, Select 3 Dots
// Triange Area has 'divide 2' -> precison : 10^(-1)
void solve() {
    double maxArea = -1;

    for (int i = 0; i < N; i++) {
        int a = dotList[i].first; int b = dotList[i].second; // A(a,b)
        for (int j = i + 1; j < N; j++) {
            int c = dotList[j].first; int d = dotList[j].second; // B(c,d)
            for (int k = j + 1; k < N; k++) {
                int e = dotList[k].first; int f = dotList[k].second; // C(e,d)
                maxArea = max(maxArea, calArea(a, b, c, d, e, f));
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