#include <cstdio>
using namespace std;

typedef struct {
	int x, y;
}xy;

int n, arr[2188][2188], A, B, C;

void Cutt(xy s, xy e) {
	bool isSame = true;
	for (int i = s.x; i <= e.x; i++) {
		for (int j = s.y; j <= e.y; j++) {
			if (arr[i][j] != arr[s.x][s.y]) {
				isSame = false;
				break;
			}
		}
		if (!isSame)
			break;
	}
	if (isSame) {
		switch (arr[s.x][s.y])
		{
		case -1:
			A++;
			break;
		case 0:
			B++;
			break;
		case 1:
			C++;
			break;
		default:
			break;
		}
		return;
	}
	int a = (e.x - s.x + 1) / 3;
	Cutt({ s.x, s.y }, { s.x + a - 1,s.y + a - 1 });
	Cutt({ s.x+a, s.y }, { s.x + a*2 - 1,s.y + a - 1 });
	Cutt({ s.x+a*2, s.y }, { s.x + a*3 - 1,s.y + a - 1 });
	Cutt({ s.x, s.y+a }, { s.x + a - 1,s.y + a*2 - 1 });
	Cutt({ s.x+a, s.y+a }, { s.x + a*2 - 1,s.y + a*2 - 1 });
	Cutt({ s.x+a*2, s.y+a }, { s.x + a*3 - 1,s.y + a*2 - 1 });
	Cutt({ s.x, s.y+a*2 }, { s.x + a - 1,s.y + a*3 - 1 });
	Cutt({ s.x+a, s.y+a*2 }, { s.x + a*2 - 1,s.y + a*3 - 1 });
	Cutt({ s.x+a*2, s.y+a*2 }, { s.x + a*3 - 1,s.y + a*3 - 1 });
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &arr[i][j]);
	Cutt({ 1,1 }, { n,n });
	printf("%d\n%d\n%d", A, B, C);
}