/*
* 1. dist의 합이 k 보다 작은 인원들로 슬라이딩 윈도우를 구성한다.
* 2. 구성한 인원들을 체크한다.
* 3. 1에서 구성한 슬라이딩 윈도우의 가장 앞 인원을 빼내고 뒤의 추가 인원들로 dist를 구성하고 k와 비교한다. 
* 4. 1~3의 과정을 모든 항목에서 검사한다.
* 
* 시간복잡도 = O(n+k)
*
* 결과는 long long 타입, 중간에 건너뛰어 슬라이딩 윈도우를 구성하는 것을 주의
*
*/

#include <iostream>
#include <vector>

using namespace std;

long long good_friend(vector<int> &v, int k) {
	int i = 1;
	int current_idx = 0;
	int size = (int)v.size();
	long long ret = 0;
	vector<int> friends(size, 0);

	// 3) 모든 항목에 대해서 검사
	while (current_idx < size) {
		int dist = 0;
		int friend_cnt = 0;

		// 1) 초기 슬라이딩 설정
		for (i = current_idx + 1; i < size; i++) {
			if (dist + v[i] - v[i - 1] > k)
				break;
			dist += v[i]-v[i-1];
			friend_cnt += 1;
		}
		friends[current_idx] = friend_cnt;

		// 2) 다음 원소를 포함하여 슬라이딩 진행
		while (++current_idx < size && dist > 0) {
			friend_cnt = friends[current_idx - 1] - 1;
			dist -= v[current_idx] - v[current_idx - 1];
			
			for (i; i < size; i++) {
				if (dist + v[i] - v[i - 1] > k)
					break;
				dist += v[i] - v[i - 1];
				friend_cnt += 1;
			}
			friends[current_idx] = friend_cnt;
		}		
	}
	
	for (int i = 0; i < size; i++)
		ret += friends[i];	

	return ret;
}

int main(){
	int n, k;
	long long sum = 0;
	string name;
	vector<vector<int>> name_length;

	name_length.resize(21);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> name;
		name_length[(int)name.length()].push_back(i);
	}
	for (int i = 2; i < 21; i++) 
		sum += good_friend(name_length[i], k);
	
	cout << sum;
}
