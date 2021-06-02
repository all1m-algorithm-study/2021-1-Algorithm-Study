import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int W, H;
	static byte[][] map;
	static final int[] dr = { -1, -1, 0, 1, 1, 1, 0, -1 }, dc = { 0, 1, 1, 1, 0, -1, - 1, - 1 };

	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	static void dfs(int r, int c) {
		if (!(0 <= r && r < W && 0 <= c && c < H))
			return;
		if (map[r][c] == 0)
			return;
		map[r][c] = 0;
		
		for (int i = 0; i < 8; i++) {
			dfs(r + dr[i], c + dc[i]);
		}

	}

	public static void main(String[] args) throws IOException {
		sb.setLength(0);
		while (true) {
			st = new StringTokenizer(br.readLine());
			H = stoi(st.nextToken());
			W = stoi(st.nextToken());
			if (W == 0 && H == 0)
				break;
			map = new byte[W][H];

			for (int i = 0; i < W; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < H; j++) {
					map[i][j] = Byte.parseByte(st.nextToken());
				}
			}
			int num = 0;

			for (int i = 0; i < W; i++) {
				for (int j = 0; j < H; j++) {
					if (map[i][j] == 1) {
						num++;
						dfs(i, j);
					}
				}
			}
			sb.append(num).append('\n');

		}

		System.out.println(sb.toString());
	}
}
