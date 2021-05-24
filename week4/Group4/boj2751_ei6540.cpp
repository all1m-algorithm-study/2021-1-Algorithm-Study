#include <iostream>
#include <vector>
#include <string>
using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

//push_back을 이렇게 자주 부르는게 좋은 방법일까?
vector<int> merge_array(vector<int>left, vector<int>right) {
	int i = 0; int j = 0; int k = 0;
	int len_left = left.size();
	int len_right = right.size();
	vector<int> ans(len_left + len_right);

	while (i < len_left && j < len_right) {
		if (left[i] < right[j]) {
			ans[k++] = left[i++];
		}
		else {
			ans[k++] = right[j++];
		}
	}
	while (i < len_left) {
		ans[k++] = left[i++];
	}
	while (j < len_right) {
		ans[k++] = right[j++];
	}

	return ans;
}

vector<int> merge_sort(vector<int>arr) {
	if (arr.size() == 1) {
		return arr;
	}

	int halfsize = arr.size() / 2;
	
	//왼쪽 부분 부르기, 0부터 반, 오른쪽 부분 부르기, 반부터 size-1
	vector<int> left;
	vector<int> right;

	left.assign(arr.begin(), arr.begin() + arr.size() / 2);
	right.assign(arr.begin() + arr.size() / 2, arr.end());
	

	//merge하기
	return merge_array(merge_sort(left), merge_sort(right));
}


void solve() {

	int N;
	cin >> N;

	vector<int> before_sort(N);
	vector<int> after_sort(N);
	
	for (int i = 0; i < N; i++) {
		cin >> before_sort[i];
	}
	
	after_sort = merge_sort(before_sort);

	for (int i = 0; i < N; i++) {
		cout << after_sort[i] << '\n';
	}
}

int main() {
	init();
	solve();
}
