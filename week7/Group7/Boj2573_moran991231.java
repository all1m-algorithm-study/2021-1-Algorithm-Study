import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	static int N, M;
	static int[][] map, temp;

	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	static int simulate() {
		int years = 0;
		int num;
		while (true) {
			num = numIceberg();
			if(num>=2)
				break;
			else if(num==0) {
				years=0;
				break;
			}
			years++;
			melt();
		}
		return years;
	}

	static void melt() {
		for (int i = 1; i < N - 1; i++) {
			for (int j = 1; j < M - 1; j++) {
				
				if (map[i][j] != 0) {
					temp[i][j] = map[i][j]-meltingAmount(i, j);
					if(temp[i][j]<0) temp[i][j]=0;
				}else
					temp[i][j]=0;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
				map[i][j] = temp[i][j];
		}
	}

	static int numIceberg() {
		int cnt = 0;
		for (int i = 1; i < N - 1; i++) {
			for (int j = 1; j < M - 1; j++) {
				if (temp[i][j] != 0) {
					cnt++;
					dfs(i, j, temp);

				}
			}
		}
		return cnt;
	}

	static void dfs(int i, int j, int[][] visited) {
		if (!(0 <= i && i < N && 0 <= j && j < M))
			return;
		if (visited[i][j] == 0)
			return;
		visited[i][j] = 0;

		dfs(i - 1, j, visited);
		dfs(i + 1, j, visited);
		dfs(i, j - 1, visited);
		dfs(i, j + 1, visited);

	}

	static int meltingAmount(int i, int j) {
		int cnt = 0;
		if (0 <= i - 1)
			if (map[i - 1][j] == 0)
				cnt++;
		if (i + 1 < N)
			if (map[i + 1][j] == 0)
				cnt++;
		if (0 <= j - 1)
			if (map[i][j - 1] == 0)
				cnt++;
		if (j + 1 < M)
			if (map[i][j + 1] == 0)
				cnt++;
		return cnt;
	}

	public static void main(String[] args) throws IOException {
		sb.setLength(0);
		st = new StringTokenizer(br.readLine());
		N = stoi(st.nextToken());
		M = stoi(st.nextToken());
		map = new int[N][M];
		temp = new int[N][M];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				temp[i][j]=map[i][j] = stoi(st.nextToken());
			}
		}
		int ret = simulate();
		System.out.println(ret);
	}
}
