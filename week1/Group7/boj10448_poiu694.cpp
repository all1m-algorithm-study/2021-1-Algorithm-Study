#include <iostream>
#include <vector>

using namespace std;

const int MAX = 43; // T(43) ~= 1000, T(44) > 1000

int T; // Test Case
vector<int> Tlist; // Trainge List..?


void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void make_Tlist() {
    // 삼각수 : 1, 3, 6, 10, 15, ... 계차수열
    int num = 1;
    int plus = 2;

    Tlist.push_back(num);
    for (int i = 0; i < MAX; i++) {
        Tlist.push_back(num + plus);
        num += plus;
        plus++;
    }
}

// 유레카!
// Tlist.size() = 43, 43 * 43 * 43 < 1e9
// {a,b,c E Tlist} : a + b + c = num -> return true
bool is_Eureka(int num) {
    for (int i = 0; i <= MAX; i++) {
        for (int j = 0; j <= MAX; j++) {
            for (int k = 0; k <= MAX; k++) {
                if (Tlist[i] + Tlist[j] + Tlist[k] > num) {
                    break;
                }
                else if (Tlist[i] + Tlist[j] + Tlist[k] == num) {
                    return true;
                }
            }
        }
    }

    return false;
}

void solve() {
    cin >> T;

    make_Tlist();

    int num;
    while (T--) {
        cin >> num;
        if (is_Eureka(num)) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }
}

int main() {
    init();
    solve();
}