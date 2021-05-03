#include <iostream>
#include <queue>

using namespace std;

int N, M;
priority_queue<long long> pq; // maxQ

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> N >> M;

    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        pq.push(-temp); // minQ로 만들자.
    }
}

void solve() {
    for (int cnt = 0; cnt < M; cnt++){
        long long num1 = -pq.top();
        pq.pop();
        long long num2 = -pq.top();
        pq.pop();

        //num1과 num2모두 num1 + num2로 초기화
        num1 = num1 + num2;

        pq.push(-num1);
        pq.push(-num1);
    }

    long long sum = 0;
    while (!pq.empty()) {
        long long num = -pq.top();
        pq.pop();

        sum += num;
    }
    cout << sum;
}

int main() {
    init();
    input();
    solve();
}