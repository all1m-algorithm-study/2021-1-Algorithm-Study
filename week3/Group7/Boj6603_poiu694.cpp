#include <iostream>
#include <vector>

using namespace std;

const int LOTTO = 6;

int N;
bool flag = true;
vector<int> list;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> N;

    if (N == 0) {
        flag = false;
        return;
    }
    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        list.push_back(temp);
    }

}

void init() {
    list.clear();
}

void make_lotto(int index, int depth, vector<int> lotto) {
    if (depth == LOTTO) {
        for (int i = 0; i < LOTTO; i++) {
            cout << lotto[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = index; i < list.size(); i++) {
        lotto.push_back(list[i]);
        make_lotto(i + 1, depth + 1, lotto);
        lotto.pop_back();
    }
}

void solve() {
    while (true) {
        init(); // list clear
        input(); // input for list

        if (!flag) { return; } // input 0

        make_lotto(0, 0, {}); // make lotto num
        cout << '\n';
    }
}

int main() {
    fastIO();
    solve();
}