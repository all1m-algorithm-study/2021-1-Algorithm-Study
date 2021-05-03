#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> aList, bList;

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
        aList.push_back(temp);
    }
    for (int i = 0; i < N; i++) {
        cin >> temp;
        bList.push_back(temp);
    }
}



void solve() {
    int sum = 0;

    for (int i = 0; i < N; i++) {
        int max_idx = max_element(bList.begin(), bList.end()) - bList.begin();
        int min_idx = min_element(aList.begin(), aList.end()) - aList.begin();
        
        sum += aList[min_idx] * bList[max_idx];

        bList[max_idx] = -1;
        aList[min_idx] = 101;
    }

    cout << sum;
}

int main(void)
{
    init();
    input();
    solve();
}
