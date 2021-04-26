/*
* 1. 가장 작은 값 2개를 추출하여 합한 결과값 2개를 다시 삽입 후 정렬 
* 
* 시간복잡도 = O(m * nlogn) (m: 반복 횟수, n: 입력 데이터)
* 
* 주의) 자료형 (최대 결과값: 39 * 10^9)
*/


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n, m;
    long long card;
    priority_queue<long long, vector<long long>, greater<long long>> cards;
    long long score = 0;

    cin >> n >> m;

    while (n--) {
        cin >> card;
        cards.push(card);
    }

    while (m--) {
        long long card1, card2;
        card1 = cards.top();
        cards.pop();
        card2 = cards.top();
        cards.pop();

        card1 = card2 = card1 + card2;

        cards.push(card1);
        cards.push(card2);
    }
    while (!cards.empty()) {
        score += cards.top();
        cards.pop();
    }
    cout << score;
}
