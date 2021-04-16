#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int num, int start, int temp, int end){
	if(num==1){
		cout << start << " " << end << '\n';
	}else{
		hanoi(num-1,start, end, temp);
		cout << start << " " << end << '\n';
		hanoi(num-1,temp, start, end);
	}
}

int main() {
	int N;
	cin >> N;
	cout << (1<<N) -1 << '\n';
	hanoi(N, 1,2,3);
}
