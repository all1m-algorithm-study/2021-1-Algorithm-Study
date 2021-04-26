#include <iostream>

using namespace std;

const int BIG = 1000000;
int N;

void init() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
}

void input() {
   cin >> N;
}

// 자릿수의 합
int sumN(int num) {
   int sum = num;
   while (num != 0) {
      sum += num % 10;
      num /= 10;
   }
   return sum;
}

void solve() {
   for (int i = 1; i <= BIG; i++) {
      if (sumN(i) == N) {
         cout << i << endl;
         return;
      }
   }
   
   cout << 0 << endl;
}

int main() {
   init();
   input();
   solve();
}