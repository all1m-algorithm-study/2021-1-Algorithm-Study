#include <iostream> 
#include <string>
#include <algorithm>
#include <utility>
#include <math.h>
#include<queue>
#include<vector>
using namespace std;


void dfs(int start, vector<int>(&list)[100001], bool (&check)[100001], int(&par)[100001]) {
	check[start] = 1;
	for (int i = 0; i < list[start].size(); i++) {
		int next = list[start][i];
		if (!check[next]) {
			par[next] = start;
			dfs(next, list, check, par);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n, a, b;
	vector<int> list[100001];
	bool check[100001] = { 0 };
	int par[100001] = { 0 };
	cin >> n;
	for (int i = 2; i <= n ; i++) {

		cin >> a >> b;
		list[a].push_back(b);
		list[b].push_back(a);
	}
	dfs(1, list, check, par);

	for (int i = 2; i <= n; i++) {
		cout << par[i] << "\n";
	}

	
}