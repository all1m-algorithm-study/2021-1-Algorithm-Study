// 1. 인덱스를 1개씩 늘리고 cnt로 확인
// 2. 방문한 적이 있다면 cnt += 1
// 3. cnt == k가 되면 출력 후 추가 작업
// 4. n 개를 출력할 때까지 반복
//
// 시간복잡도 = O(n * k) (k 까지의 탐색을 n번 진행)

#include <iostream>
#include <vector>

using namespace std;

void josephus(vector<int> &people, int n, int k) {
	vector<bool> visited(n, false);
	int idx = k-1;
	int cnt = 0;
	int loop = 1;

	cout << "<" << people[idx];
	visited[idx] = true;

	while(loop < n){
		if (cnt == k) {
			cout << ", " << people[idx];
			visited[idx] = true;
			cnt = 0;
			loop += 1;
		}
		if (!visited[(idx + 1) % n])
			cnt += 1;
		idx = (idx + 1) % n;
	}
	cout << ">";

	return;
}
int main(){
	int n, k;
	vector<int> people;
	
	cin >> n >> k;

	for (int i = 0; i < n; i++) 
		people.push_back(i + 1);	

	josephus(people, n, k);
	return 0;
}

