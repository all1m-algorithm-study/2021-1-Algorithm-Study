#include <iostream>
using namespace std;
int main()
{
	int N, K, arr[1001], start = 0, go, cnt = 0;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		arr[i] = i;
	go = K-1;
	cout << "<";

	for (int i = K; cnt < N; i++) {
		if (i > N) i = 1;
		if (arr[i] == -1) continue;
		go++;
		if (go == K) {
			go = 0;
			if (cnt == N-1)
				cout << i;
			else
				cout << i << ", ";
			arr[i] = -1;
			cnt++;
		}
	}
	cout << ">";
}