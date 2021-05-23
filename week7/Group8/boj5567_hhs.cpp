#include <stdio.h>
#pragma warning(disable:4996)
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int students;//문제에서의 N(node)
	int listLen;//문제에서의 M(edge)
	int str, des;
	int rel;

	/*입력 1 - 동창의 수, 입력받을 친구관계 케이스 수*/
	scanf("%d", &students);
	scanf("%d", &listLen);
	
	/*그래프로 만들 벡터 생성*/
	vector<int>* graph = new vector<int>[students+1];//1~student까지(idx 0 사용 안하기 위함) 
	vector<int> invite; //최종 초대된 친구들 노드
	
	
	/*입력 2 - 링크드 리스트처럼 친구 관계를 입력*/
	for (int i = 0; i < listLen; i++) {
		scanf("%d %d", &str, &des);

		graph[str].push_back(des);
		graph[des].push_back(str);
	}

	/*결혼식 초대 인원 체크*/
	while (1) {
		if (graph[1].empty())
			break;

		//친구
		rel = graph[1].back();
		printf("친구: %d\n", rel);
		auto it = find(invite.begin(), invite.end(), rel);//반복자
		if (it == invite.end()) {//초대 리스트에 없으면
			printf("초대 리스트에 추가한 친구: %d\n", rel);
			invite.push_back(rel);//추가
		}
		graph[1].pop_back();

		//친구의 친구
		while (1) {
			if (graph[rel].empty())
				break;
			printf("친구의 친구: %d\n", graph[rel].back());
			auto it_f = find(invite.begin(), invite.end(), graph[rel].back());
			if (graph[rel].back() != 1 && it_f == invite.end()) {//상근이가 아니면서 초대리스트에 없는 친구 
				printf("초대리스트에 추가한 친구의 친구: %d\n", graph[rel].back());
				invite.push_back(graph[rel].back());
			}
			graph[rel].pop_back();
		}
	}

	printf("\n초대할 친구의 수: %d\n", invite.size());

	return 0;
}