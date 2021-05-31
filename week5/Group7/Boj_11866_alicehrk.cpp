#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N, K; // N명의 사람, 양의 정수 K가 주어짐. 
	cin >> N >> K;

	//큐 생성
	queue<int> q;

    //N만큼 반복하면서 큐에 원소를 추가(숫자 삽입)
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	cout << "<";
    int count = 1;

    //empty() -> 큐가 비어있으면 true 아니면 false 반환 함수
    while (!q.empty()) { // 비어있지 않을 때 반복

        if (count % K == 0) { // K번째 사람이면 pop(삭제)
            int element = q.front(); //큐 제일 앞에 있는 원소를 element에 저장
            q.pop(); // 큐에 있는 원소를 삭제(앞에)
            if (q.empty()) {
                cout << element << ">"; //더이상 없을 때는 >로 닫아주기
            }
            else {
                cout << element << ", "; //아니라면 ,로 나머지 요세푸스 순열 원소 이어서 찾기
            }
        } 

        else { // K번째가 아니라면 pop 후에 다시 push 
            int num = q.front(); //큐 제일 앞에 있는 원소를 num에 저장
            q.pop(); 
            q.push(num); // 큐의 뒷부분에 제일 앞에 있던 원소를 추가
        }

        count++;

    }
}