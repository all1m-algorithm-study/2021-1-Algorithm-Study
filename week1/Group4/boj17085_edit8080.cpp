/*
*   1. 겹치지 않는 두 점(p1, p2)을 선택한다. 
*   2. 길이를 지정한다. (0 ~ 7)
*   3. 점에서 시작한 십자가가 게임판을 벗어난다면 false를 return한다.
*   4. p1에 대한 십자가를 탐색할 때 방문한 점은 visit 배열에 true로 표기한다.
*   5. p2에 대한 십자가를 탐색할 때 탐색한 점의 visit 배열이 true 면 false를 return한다.
* 
*   시간복잡도 = O(n^5) (n : board의 크기 (width * height), len = n/2)
*/


#include <iostream>

#define SIZE 16

int maxArea = 1;
int direction[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
char board[SIZE][SIZE];
int n, m;

using namespace std;

inline int area(int length) {
    return length * 4 + 1;
}
bool isCross(bool (*visit)[SIZE], int x, int y, int length) {
    for (int len = 0; len <= length; len++) {
        for (int i = 0; i < 4; i++) {
            int nextX = x + direction[i][0] * len;
            int nextY = y + direction[i][1] * len;

            if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m)
                return false;

            else {
                if (board[nextX][nextY] != '#' || visit[nextX][nextY])
                    return false;
            }
        }
    }
    for (int len = 0; len <= length; len++) {
        for (int i = 0; i < 4; i++) {
            int nextX = x + direction[i][0] * len;
            int nextY = y + direction[i][1] * len;
            visit[nextX][nextY] = true;
        }
    }
    return true;
}

int main(){
    cin >> n >> m;

    for (int i = 0; i < n; i++) 
        cin >> board[i];

    for (int x1 = 0; x1 < n; x1++) {
        for (int y1 = 0; y1 < m; y1++) {
            for (int x2 = 0; x2 < n; x2++) {
                for (int y2 = 0; y2 < m; y2++) {
                    
                    if (x1 != x2 || y1 != y2){
                        for (int len1 = 0; len1 <= 7; len1++) {
                            for (int len2 = 0; len2 <= 7; len2++) {
                                bool visit[SIZE][SIZE] = { false };

                                if (isCross(visit, x1, y1, len1) && isCross(visit, x2, y2, len2)) {
                                    int cross1 = area(len1);
                                    int cross2 = area(len2);

                                    maxArea = max(maxArea, cross1 * cross2);
                                }
                            }

                        }
                    }
                }
            }

        }
    }

    cout << maxArea;
    
    return 0;
}
