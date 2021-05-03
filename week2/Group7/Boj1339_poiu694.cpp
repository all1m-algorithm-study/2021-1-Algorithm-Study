#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int N;
int alpha[26];
vector<string> list;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

// 왼쪽으로 갈 수록 배열의 길이가 증가
bool cmp(int A, int B) {
    if (A > B) {
        return true;
    }
    else {
        return false;
    }
}

void input() {
    cin >> N;

    string temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        list.push_back(temp);
    }
}

// ABC + AB : (100A + 10B + 1C) + (10A) +(1B)
void solve() {
    for (int i = 0; i < list.size(); i++) {
        int pow = 1;

        for (int j = list[i].length() - 1; j >= 0; j--) {
            char word = list[i][j];
            alpha[word - 'A'] += pow;
            pow *= 10;
        }
    }
    
    sort(alpha, alpha + 26, cmp);
    
    int sum = 0;
    int temp_num = 9;
    for (int i = 0; i < 26; i++) {
        if (alpha[i] == 0) {
            break;
        }

        sum += (alpha[i] * temp_num--);
    }

    cout << sum;
}

int main() {
    init();
    input();
    solve();
}

