 

import java.io.*;
import java.util.Arrays;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();

	static char[][] tri;

	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	static void makeTri(int N) {
		tri = new char[N][N * 2 - 1];
		for (int i = 0; i < N; i++) {
			char[] line = tri[i];
			Arrays.fill(line, ' ');

			for (int s = N - i - 1; s < N + i; s++)
				line[s] = '*';
		}
	}

	static void eraseInvertedTri(int r, int c, int n) {
		if (n == 1) {
			tri[r][c] = ' ';
			return;
		}
		for (int i = 0; i < n; i++) {
			char[] line = tri[r + i];

			for (int b = c + i; b < 2 * (n - i) - 1 + c + i; b++)
				line[b] = ' ';
		}

	}

	static void divideTri(int r, int c, int n) {
		if (n == 1)
			return;
		int halfN = n / 2;
		eraseInvertedTri(r + halfN, c - halfN + 1, halfN);

		divideTri(r, c, halfN);
		divideTri(r + halfN, c - halfN, halfN);
		divideTri(r + halfN, c + halfN, halfN);
	}

	public static void main(String[] args) throws IOException {
		sb.setLength(0);
		int N = stoi(br.readLine());
		
		makeTri(N);
		divideTri(0, N - 1, N);
		
		for (char[] line : tri)
			sb.append(line).append('\n');
		System.out.print(sb.toString());

	}

}