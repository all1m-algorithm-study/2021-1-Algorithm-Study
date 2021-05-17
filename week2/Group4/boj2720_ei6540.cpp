#include <iostream>
#include <cstring>

using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve() {
    
    int T;
    int cnt;
    cin >> T;

    while (T--) {
        int coins[4] = { 0, };
        cin >> cnt;
        while (cnt > 0) {

            if (cnt >= 25) {
                coins[0]++;
                cnt -= 25;
            }
            else if (cnt >= 10) {
                coins[1]++;
                cnt -= 10;
            }
            else if (cnt >= 5) {
                coins[2]++;
                cnt -= 5;
            }
            else if (cnt >= 1) {
                coins[3]++;
                cnt -= 1;
            }
        }
        cout << coins[0] << " " << coins[1] << " " << coins[2] << " " << coins[3]<<'\n';
    }

}

int main() {
    init();
    solve();
}