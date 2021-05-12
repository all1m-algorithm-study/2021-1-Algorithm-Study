#include <stdio.h>
#pragma warning(disable:4996)
#include <stdlib.h>
#include <algorithm>
using namespace std;

typedef struct conference {
	int start = 0;
	int end = 0;
}CONF;

int compare(const void* A, const void* B);

int main(void) {
	CONF c[100000];
	int num;
	int count = 0;
	int minEnd = 0;

	scanf("%d", &num);

	//c = (CONF*)malloc(sizeof(CONF) * num);

	for (int i = 0; i < num; i++) {
		scanf("%d %d", &(c[i].start), &(c[i].end));
	}

	//sort(c, c + num, compareEnd);
	qsort(c, num, sizeof(c[0]), compare);

	minEnd = c[0].end;
	count++;

	for (int i = 1; i < num; i++) {
		if (c[i].start >= minEnd) {
			minEnd = c[i].end;
			count++;
		}
	}

	printf("%d", count);
	
	//free(c);
	return 0;
}
int compare(const void* A, const void* B)
{
	CONF* ptA = (CONF*)A;
	CONF* ptB = (CONF*)B;

	if(ptA->end != ptB->end){
		if (ptA->end < ptB->end) return -1;
		else if (ptA->end > ptB->end) return 1;
		else return 0;
	}
	else {
		if (ptA->start < ptB->start) return -1;
		else if (ptA->start > ptB->start) return 1;
		else return 0;
	}
}