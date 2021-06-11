#include <iostream>
#include <queue>

/*
	[Silver 1]
	토마토

	N*M 행렬을 입력으로, ( 2 <= N,M <= 1,000 )
	-1 : 빈 칸
	1 : 익은 칸
	0 : 안 익은 칸
	
	안 익은 칸은 익은 칸이 옆에 있는 경우 하루가 지나면 익게 된다. ( 대각선 불가능 )

	전체가 다 익는데 걸리는 시간? (다 익을 수 없다면 -1을 출력한다.)

	---
	[idea]
	1. -1인 칸을 제외하고, BFS로 탐색한다.
		- BFS는 가장 바깥 영역에서만 탐색하므로 이 문제에 적절하다.
	2. O(N*M) 시간 동안 1인 칸의 위치를 모두 파악한다.
		- 0의 개수를 파악해 BFS가 끝났을 때 비교 용도로 사용한다.
	3. 1인 칸들에서 순차적으로 BFS를 시작한다. BFS로 칸을 방문할 때마다 날짜를 ++한다.
		- 방문한 경우 0->1로 바꾼다.
		- 방문한 0의 개수를 센다.
	4. 큐가 빈 경우, 
		- 모든 BFS가 끝난 후에도 방문하지 못한 0 칸이 남아있는 경우 -1을 반환한다.
		- 각 BFS가 끝난 경우, days 변수의 값보다 크면 갱신한다.
*/

using namespace std;

typedef struct Point7576
{
    int x, y, day;

    // 그냥 생성할 수가 없어서 대충
    Point7576() {}

    Point7576(int x, int y, int day)
    {
        this->x = x;
        this->y = y;
        this->day = day;
    }
} Point7576;

// [y,x] = 동서남북
// [x,y] = 북남서동
const int px[] = {1, -1, 0, 0};
const int py[] = {0, 0, -1, 1};

int main()
{
    int i, j, tmp, N, M, nx, ny, starting_num = 0, zero_cnt = 0, zero_visited = 0, days = 0;
    cin >> N >> M;
    Point7576 starting[N * M];
    bool visited7576[M][N] = {false}; // 왜 [0,1..N-1]이 255 이런 값으로 초기화되지..?
    int matrix[M][N] = {0};
    // (x, y)로 하지 않고, 그냥 범위만 [Y, X]로 쓰고 나머진 그냥 써도 된다! (신기하당)
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            cin >> tmp;
            matrix[i][j] = tmp;
            visited7576[i][j] = false; // 버그걸려서 필요함;;
            if (tmp == 1)
                starting[starting_num++] = Point7576(i, j, 0);
            else if (tmp == 0)
                zero_cnt++;
        }
    }

    Point7576 cur;
    queue<Point7576> Q;
    // 시작점은 탐색이 끝날 때까지 기다린 후 차례로 수행
    for (i = 0; i < starting_num; i++)
        Q.push(starting[i]);

    while (!Q.empty())
    {
        cur = Q.front();
        Q.pop();

        if (visited7576[cur.x][cur.y])
            continue;

        visited7576[cur.x][cur.y] = true;
        matrix[cur.x][cur.y] = 1; // 디버깅 용도
        // 방문한 0 추가
        zero_visited++;
        // 현재 방문한 day가 더 크면 갱신
        days = cur.day > days ? cur.day : days;
        for (j = 0; j < 4; j++)
        {
            nx = cur.x + px[j];
            ny = cur.y + py[j];
            if (nx < 0 || ny < 0 || nx >= M || ny >= N)
                continue;
            if (matrix[nx][ny] == -1)
                continue;
            Q.push(Point7576(nx, ny, cur.day + 1));
        }
    }

    if (zero_cnt == zero_visited - starting_num)
        cout << days << "\n";
    else
        cout << "-1\n";
    return 0;
}
