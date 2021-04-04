#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> cards;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> mask(N-3, 0);
    mask.resize(N, 1);

    for (int i=0; i < N; ++i) {
        int c;  cin >> c;
        cards.push_back(c);
    }
    int ans = 0;
    do {
        int sum = 0;
        for(int i=0; i<N; i++) {
            if (mask[i])
                sum += cards[i];
        }
        if (sum <= M)
            ans = max(ans, sum);
    } while(next_permutation(mask.begin(), mask.end()));
    cout << ans;
}