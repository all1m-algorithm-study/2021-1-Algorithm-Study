#include <iostream>
#include <algorithm>

using namespace std;

const int dwarf = 9;
int list[9];
int keySum = 0; // 키썸~

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    for (int i = 0; i < dwarf; i++) {
        cin >> list[i];
        keySum += list[i];
    }
}

// Brute Force
// if(keySum - (a+b) == 100) : a&b is fake
// data[a, b] -> -1, print data[i] != -1
void solve() {
    bool flag = false; // a+b+100 = keySum -> flag = true

    // who is real?
    for (int i = 0; i < dwarf; i++) {
        for (int j = i + 1; j < dwarf; j++) {
            if (keySum - (list[i] + list[j]) == 100) {
                list[i] = -1;
                list[j] = -1;
                flag = true;
                break;
            }
        }

        if (flag) {
            break;
        }
    }

    // print not fake
    for (int i = 0; i < dwarf; i++) {
        if (list[i] != -1) {
            cout << list[i] << '\n';
        }
    }
}

int main() {
    init();
    input();
    solve();
}