/*
* 1. 1번 점수의 순위를 기준으로 오름차순 정렬
* 2. 2번 점수 탐색 => 2번 점수가 standard보다 작으면 뽑기 (count+=1)
* 3. 사원을 뽑으면 standard 변경
* 
* 시간복잡도 = O(t* nlogn) (t: 루틴 횟수, n: 입력 데이터 수)
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int t, n;
	cin >> t;

	while (t--) {
		vector<pair<int, int>> all_score;
		int score1, score2;
		int count = 1;
		int standard;

		cin >> n;
		
		for (int i = 0; i < n; i++) {
			cin >> score1 >> score2;
			all_score.push_back(make_pair(score1, score2));
		}
		sort(all_score.begin(), all_score.end());
		standard = all_score[0].second;
				
		for (int i = 1; i < n; i++) {
			if (all_score[i].second <= standard) {
				count++;
				standard = all_score[i].second;
			}				
		}
		cout << count << '\n';
	}
}