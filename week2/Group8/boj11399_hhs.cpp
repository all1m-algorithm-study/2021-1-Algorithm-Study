#include<stdio.h>
#pragma warning(disable:4996)
#include<stdlib.h>

int compare(const void* A, const void* B);
int total(int* arr, int num);
int main(void) {
	int person;
	int* minute;
	int result = 0;

	scanf("%d", &person);

	minute = (int*)malloc(sizeof(int) * person);

	for (int i = 0; i < person; i++) {
		scanf("%d", &minute[i]);
	}

	qsort(minute, person, sizeof(minute[0]), compare);

	for (int i = 0; i < person; i++) {
		result += total(&minute[0], i);
		//printf("%d\n", result);
	}
	printf("%d\n", result);

	return 0;
}
int compare(const void* A, const void* B)
{
	int* ptA = (int*)A;
	int* ptB = (int*)B;

	if (*ptA < *ptB) return -1;
	else if (*ptA > *ptB) return 1;
	else return 0;

}
int total(int* arr, int num) {
	int res = 0;
	
	for (int i = 0; i < num+1; i++)
		res += arr[i];
	//printf("res = %d\n", res);

	return res;
}