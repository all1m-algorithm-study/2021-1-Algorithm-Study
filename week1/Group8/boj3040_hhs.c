#include <stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
#define DNUM 9//난쟁이 9명

int main(void) {
	int dwarf[DNUM];
	int dwarfSum = 0;
	int fake[2] = { 0, };
	int result = 0;

	//난쟁이 모자 숫자 입력해서 dwarfSum에 저장
	for (int i = 0; i < DNUM; i++) {
		scanf("%d", &dwarf[i]);
		dwarfSum += dwarf[i];
	}

	//숫자의 총합에서 두 가지 숫자를 뺐을 때 합이 100이면 fake 배열에 숫자 저장 후 반복문 탈출
	for (int i = 0; i < DNUM; i++) {
		for (int j = i + 1; j < DNUM; j++) {
			if (dwarfSum-(dwarf[i]+dwarf[j]) == 100){
				fake[1] = dwarf[j];
				result = 1;
				break;
			}
		}
		if (result){
			fake[0] = dwarf[i];
			break;
		}
	}

	//fake 배열의 숫자들과 같지 않을 때만 출력
	for (int i = 0; i < DNUM; i++) {
		if (dwarf[i] != fake[0] && dwarf[i] != fake[1]){
			printf("%d\n", dwarf[i]);
		}
	}


	return 0;
}