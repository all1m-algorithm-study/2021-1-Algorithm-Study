#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> weight;

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
        weight.push_back(temp);
    }
}

// 전체 경우의수 : 2^n - 1
// n<=1000이므로 짱 크다
void solve() {
    sort(weight.begin(), weight.end());

    // A1 + A2 + ... + An (Ai-1 <= Ai)
    // Sn-1(의 합이) An보다 크다면 답은 Sn +1
    // Sn-2 > An-1 답은 Sn-1 + 1
    // An-1까지의 합으로 An보다 작은 모두를 구할 수 있따.

    int prefixSum = 0;
    for (int i = 0; i < weight.size() - 1; i++) {
        if (weight[0] != 1) {
            break;
        }
        prefixSum += weight[i];

        if (prefixSum + 1 >= weight[i + 1]) {
            continue;
        }
        else {
            break;
        }
    }
    
    if (prefixSum + 1 >= weight[N - 1]) {
        prefixSum += weight[N - 1];
    }

    cout << prefixSum + 1;
}

int main() {
    init();
    input();
    solve();
}