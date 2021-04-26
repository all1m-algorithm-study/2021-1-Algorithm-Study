#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int n;
        int q, d, nk, p;
        cin >> n;
        q = n / 25;
        n %= 25;
        d = n / 10;
        n %= 10;
        nk = n / 5;
        n %= 5;
        p = n;
        cout << q << " " << d << " " << nk << " " << p << endl;
    }
}