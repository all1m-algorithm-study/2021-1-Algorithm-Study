#include <bits/stdc++.h>
using namespace std;

int n;
double x[35];
double y[35];
double maxval;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    cout << fixed;
    cout.precision(9);

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (maxval < 0.5 * abs(((x[i] * y[j]) + (x[j] * y[k]) + (x[k] * y[i])) - ((y[i] * x[j]) + (y[j] * x[k]) + (y[k] * x[i])))) {
                    maxval = 0.5 * abs(((x[i] * y[j]) + (x[j] * y[k]) + (x[k] * y[i])) - ((y[i] * x[j]) + (y[j] * x[k]) + (y[k] * x[i])));
                }
            }
        }
    }
    cout << maxval;
}