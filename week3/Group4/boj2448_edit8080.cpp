/*
* 1. 전체 삼각형 구성
* 2. 탐색하는 삼각형의 가운데를 빈 삼각형으로 설정한다.
* 3. 중앙, 좌하, 하단 중앙을 기준으로 길이를 1/3으로 줄여가며 재귀적으로 함수를 실행한다.
* 4. 기저조건 : (길이) = 3인 경우
* 
* 시간복잡도 = O(n * log3(n))
*/

#include <iostream>
#include <cstring>

using namespace std;

void blank_center(char (*triangle)[6143], int x, int y, int length) {
    if (length == 3) {
        triangle[x - 1][y + 2] = ' ';
        return;
    }
   
    int standard_x = x - length / 2 + 1;
    int standard_y = y + length / 2;
    int step = 0;

    for (int i = 0; i < length / 2 ; i++) {
        for (int j = step; j < length - 1 - step; j++) {
            triangle[standard_x + i][standard_y + j] = ' ';
        }
        step += 1;
    }

    blank_center(triangle, standard_x - 1, standard_y, length/2);
    blank_center(triangle, x, y, length/2);
    blank_center(triangle, x, y+length, length/2);

    return;
}

int main(){
    int n;
    char triangle[3072][6143];
    cin >> n;

    memset(triangle, ' ', sizeof(triangle));
    int step = 0;

    for (int i = 0; i < n; i++) {
        for (int k = (n-1) - step; k <= (n-1) + step; k++) {
            triangle[i][k] = '*';
        }
        step += 1;
    }
    blank_center(triangle, n - 1, 0, n);
        
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            cout << triangle[i][j];
        }
        cout << '\n';
    }
    return 0;
}
