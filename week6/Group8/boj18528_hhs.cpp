#include <stdio.h>
#pragma warning(disable:4996)
#include <stdlib.h> //malloc, free
#include <string.h> //strcmp

/*큐 구현 코드(더블 링크드 리스트로 구현)*/

//구조체 선언
typedef struct node {
	int data;
	struct node* prev;
	struct node* next;
}Node;

typedef struct list {
	Node* header, * trailer;
	int numbers = 0;
}List;

//함수 원형 정의
void init(List* list);
Node* getNode(int data, Node* prev, Node* next);

void push(List* list, Node* prevNode, int data);
void pop(List* list);
void size(List* list);
void empty(List* list);
void front(List* list);
void back(List* list);

//main code
int main(void) {
	List list;
	Node* node;
	char cmd[10];
	int data;
	int isFirstNode = 1;
	int tCase;

	scanf("%d", &tCase);

	init(&list);//리스트 초기화

	for (int i = 0; i < tCase; i++) {
		scanf("%s", cmd);

		/*
			strcmp: 문자열 비교 함수
			str1 < str2 = 음수 반환
			str1 > str2 = 양수 반환
			str1 = str2 = 0 반환
		*/

		if (!strcmp(cmd, "pop")) {
			//printf("pop func\n");
			pop(&list);
			continue;
		}
		if (!strcmp(cmd, "size")) {
			//printf("size func\n");
			size(&list);
			continue;
		}
		if (!strcmp(cmd, "empty")) {
			//printf("empty func\n");
			empty(&list);
			continue;
		}
		if (!strcmp(cmd, "front")) {
			//printf("front func\n");
			front(&list);
			continue;
		}
		if (!strcmp(cmd, "back")) {
			//printf("back func\n");
			back(&list);
			continue;
		}

		//숫자 입력 받는 명령어
		scanf("%d", &data);

		if (!strcmp(cmd, "push")) {
			//printf("push func\n");
			//노드 추가하기
			if (isFirstNode == 1) {
				push(&list, (&list)->header, data);
				isFirstNode = 0;
			}
			else
				push(&list, (&list)->trailer->prev, data);
		}
		else
			printf("wrong command\n");


	}
	return 0;
}

/*
	list 초기화 함수
	(header, trailer node 생성)
*/
void init(List* list) {
	list->header = getNode(-1, NULL, NULL);
	list->trailer = getNode(-1, NULL, NULL);

	list->header->next = list->trailer;
	list->trailer->prev = list->header;
}

/*
	node 생성 함수
*/
Node* getNode(int data, Node* prev, Node* next) {
	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->prev = prev;
	newNode->next = next;
	return newNode;
}

/*
	push 함수
	- node 생성
	- node의 prev는 header 혹은 마지막으로 생성된 노드(trailer의 prev)
	- node의 next는 trailer
*/
void push(List* list, Node* prevNode, int data) {
	Node* newNode = getNode(data, NULL, NULL);

	//첫번째 생성 node: 생성할 노드의 이전 노드가 header
	if (prevNode->data == -1) {//
		newNode->prev = list->header;
		list->header->next = newNode;

		newNode->next = list->trailer;
		list->trailer->prev = newNode;
	}
	//그 이후 생성 node
	else {
		newNode->prev = prevNode;
		prevNode->next = newNode;

		newNode->next = list->trailer;
		list->trailer->prev = newNode;
	}
	(list->numbers)++;

	return;
}

/*
	pop 함수
	- node 제거, 메모리 free
	- 첫번째 노드를 삭제하는 기능
	- 빈 노드거나 없으면 예외처리
	- node의 prev를 다음 node의 prev로
	- node의 next를 이전 node의 next로
*/
void pop(List* list) {
	Node* ptr = list->header->next;//ptr은 첫번째 node 가리킴

	if (ptr->data == -1)//빈 list인 경우
		printf("-1\n");

	else {//첫번째 data pop
		printf("%d\n", ptr->data);
		list->header->next = ptr->next;
		ptr->next->prev = list->header;
		free(ptr);
	}

	if ((list->numbers) > 0)
		(list->numbers)--;
	return;
}

//큐 크기 출력
void size(List* list) {
	printf("%d\n", list->numbers);
	return;
}

//큐가 비었는지 확인-비었으면 1, 안비었으면 0
void empty(List* list) {
	Node* ptr = list->header->next;//ptr은 첫번째 node 가리킴

	if (ptr->data == -1)//바로 다음 노드가 trailer면 빈 스택
		printf("1\n");
	else
		printf("0\n");

	return;
}

//맨 앞 data 출력
void front(List* list) {
	Node* ptr = list->header->next;//ptr은 첫번째 node 가리킴

	if (ptr->data == -1)//빈 node면
		printf("-1\n");
	else printf("%d\n", ptr->data);

	return;
}

//맨 뒤 data 출력
void back(List* list) {
	Node* ptr = list->trailer->prev;//ptr은 마지막 node 가리킴

	if (ptr->data == -1)//빈 node면
		printf("-1\n");
	else printf("%d\n", ptr->data);

	return;
}