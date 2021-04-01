#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int div_sum(int n) {
    string ns = to_string(n);
    int rtn = n;
    for (const char c: ns)
        rtn += c - '0';
    return rtn;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;  cin >> N;
    int ans = 2e8;
    for(int i=N-1; i>0; i--)
        if (N == div_sum(i))
            ans = i;
    if (ans == 2e8)
        ans = 0;
    cout << ans;
}