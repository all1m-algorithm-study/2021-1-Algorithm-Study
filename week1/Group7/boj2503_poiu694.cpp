#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> list; // Question
vector<pair<int, int>> ans; // Number Of Strike & Ball 

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> N;

    int quest, strike, ball;
    for (int i = 0; i < N; i++) {
        cin >> quest >> strike >> ball;
        list.push_back(quest);
        ans.push_back({ strike, ball });
    }
}

// num 은 생각하고 있는 숫자
// 조건에 맞는지 하나씩 확인해보자..!
bool is_can(int num) {
    int hun = num / 100;
    num %= 100;
    int ten = num / 10;
    int one = num % 10;

    // 중복 숫자 불가능
    if (hun == ten || ten == one || hun == one) {
        return false;
    }
    // 0 숫자 불가능
    if (hun == 0 || ten == 0 || one == 0) {
        return false;
    }

    for (int i = 0; i < N; i++) {
        int list_hun = list[i] / 100;
        int list_ten = (list[i] % 100) / 10;
        int list_one = list[i] % 10;

        int str = 0; int bl = 0;
        // check strike
        if (hun == list_hun) {
            str++;
        }
        if (ten == list_ten) {
            str++;
        }
        if (one == list_one) {
            str++;
        }

        // check ball
        if (hun == list_ten || hun == list_one) {
            bl++;
        }
        if (ten == list_hun || ten == list_one) {
            bl++;
        }
        if (one == list_hun || one == list_ten) {
            bl++;
        }

        if (str != ans[i].first || bl != ans[i].second) {
            return false;
        }
    }

    return true;
}

// 111 ~ 999까지 하나씩 확인해보자..>??!
// 조건에 역 대입
void solve() {
    int cnt = 0;

    for (int i = 123; i <= 987; i++) {
        if (is_can(i)) {
            cnt++;
        }
    }

    cout << cnt;
}

int main() {
    init();
    input();
    solve();
}
