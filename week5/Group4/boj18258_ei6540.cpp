#include <iostream>
#include <string>
#include <cstring>
//using namespace std;

void fast_io() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

typedef struct Queue {
	int data[2000000];
	int front, rear;
} Queue;

void init(Queue* q) {
	q->front = q->rear = -1;
}
int is_empty(Queue* q) {
	//front와 rear가 같으면 큐는 비어있음
	return (q->front == q->rear);
}

int size(Queue* q) {
	if (is_empty(q)) {
		return 0;
	}
	return (q->rear - q->front);
}

void push(Queue* q, int data) {
	q->data[++(q->rear)] = data;
}

int pop(Queue* q) {
	//비었으면 에러 발생시킴
	if (is_empty(q)) return -1;
	return q->data[++(q->front)];
}

int front(Queue* q) {
	if (is_empty(q)) return -1;
	return q->data[q->front + 1];
}

int back(Queue* q) {
	if (is_empty(q)) return -1;
	return q->data[q->rear];
}

int solve() {
	Queue q;
	init(&q);
	int N;
	std::cin >> N;
	while (N--) {
		char str[6];
		std::cin >> str;
		if (!strcmp(str, "push")) {
			int data = 0;
			std::cin >> data;
			push(&q, data);
		}
		else if (!strcmp(str, "front")) {
			std::cout << front(&q) << '\n';
		}
		else if (!strcmp(str, "back")) {
			std::cout << back(&q) << '\n';
		}
		else if (!strcmp(str, "pop")) {
			std::cout << pop(&q) << '\n';
		}
		else if (!strcmp(str, "size")) {
			std::cout << size(&q) << '\n';
		}
		else if (!strcmp(str, "empty")) {
			std::cout << is_empty(&q) << '\n';
		}
	}
	return 0;
}




int main() {
	fast_io();
	solve();
}
