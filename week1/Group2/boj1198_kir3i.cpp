#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
    int x;
    int y;
};

vector<point> points;

double area(const vector<point> &p) {
    double rtn = 0;
    point p1 = p[0];
    point p2 = p[1];
    point p3 = p[2];
    rtn += p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
    rtn -= p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
    rtn /= 2;
    return abs(rtn);
}

int main(void) {
    int N;  cin >> N;
    vector<int> mask(N-3, 0);
    mask.resize(N, 1);

    for(int i=0; i<N; i++) {
        int x, y;   cin >> x >> y;
        points.push_back({x, y});
    }

    double ans = 0;
    do {
        vector<point> para;
        for(int i=0; i<N; i++)
            if(mask[i])
                para.push_back(points[i]);
        ans = max(ans, area(para));
    } while(next_permutation(mask.begin(), mask.end()));

    printf("%.9lf", ans);
}