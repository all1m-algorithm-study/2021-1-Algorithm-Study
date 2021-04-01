#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>


using namespace std;

unordered_set<int> hat;

void print_ans(int trash1, int trash2) {
    for(const int &x: hat) {
        if (x != trash1 && x != trash2)
            cout << x << "\n";
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int sum = 0;
    for(int i=0; i<9; i++) {
        int n;  cin >> n;
        hat.insert(n);
        sum += n;
    }

    for(const int &x: hat) {
        if (hat.count((sum - x) - 100)) {
            print_ans(x, (sum - x)-100);
            break;
        }
    }
}