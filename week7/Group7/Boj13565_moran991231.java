import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	static final int[] dr = { 0, -1, 0, 1 }, dc = { 1, 0, -1, 0 };
	static int M, N;
	static char[][] material;

	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	static boolean dfs(int r, int c) {
		if (!(0 <= r && r < M && 0 <= c && c < N))
			return false;
		if (material[r][c] == '1')
			return false;
		if(r==M-1)
			return true;
		material[r][c] = '1';
		for (int i = 0; i < 4; i++)
			if (dfs(r + dr[i], c + dc[i]))
				return true;

		return false;
	}

	public static void main(String[] args) throws IOException {

		st = new StringTokenizer(br.readLine());
		M = stoi(st.nextToken());
		N = stoi(st.nextToken());

		material = new char[M][];
		for (int i = 0; i < M; i++) {
			material[i] = br.readLine().toCharArray();
		}

		boolean ret = false;
		for (int j = 0; j < N; j++) {
			if (material[0][j] == '0')
				if (dfs(0, j)) {
					ret = true;
					break;
				}
		}
		System.out.println(ret ? "YES" : "NO");

	}
}
