#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> list;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> N;

    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        list.push_back(temp);
    }
}

bool cmp(int a, int b) {
    return a > b;
}

void solve() {
    sort(list.begin(), list.end(), cmp);

    int max = -1;
    for (int i = 0; i < N; i++) {
        if ((i + 1) * list[i] > max) {
            max = (i + 1) * list[i];
        }
    }


    cout << max;
}

int main() {
    init();
    input();
    solve();
}