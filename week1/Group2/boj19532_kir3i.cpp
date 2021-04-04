#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    bool ok = false;
    for(int x=-999; x<1000 && !ok; x++)
        for(int y=-999; y<1000 && !ok; y++)
            if (a*x+b*y == c && d*x+e*y == f) {
                cout << x << " " << y;
                ok = true;
            }
}