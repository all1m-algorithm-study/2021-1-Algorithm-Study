#include<stdio.h>
#include<vector>
#pragma warning(disable:4996)
using namespace std;

void dfs(int num, vector<int>* graph);
int visited[101] = { 0, };
int result = 0;
int main(void) {
	int computers;
	int edge;
	int str, des;
	int check;


	scanf("%d", &computers);
	scanf("%d", &edge);

	vector<int>* graph = new vector<int>[computers + 1];
	vector<int> virus;

	for (int i = 0; i < edge; i++) {
		scanf("%d %d", &str, &des);

		graph[str].push_back(des);
		graph[des].push_back(str);
	}

	dfs(1, graph);
	printf("%d\n", result);

	return 0;
}

void dfs(int num, vector<int>* graph) {
	visited[num] = 1;
	for (int i = 0; i < graph[num].size(); i++) {
		if (visited[graph[num][i]]==0) {
			dfs(graph[num][i], graph);
			result++;
		}
	}
	return;
}