 

import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	static int[] pick = new int[6];
	static int K;
	static int[] S;

	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	static void lotto(int idxS, int cnt) {
		if (cnt == 6) {
			printPick();
			return;
		}
		for (int i = idxS; i < K; i++) {
			pick[cnt] = S[i];
			lotto(i + 1, cnt + 1);
		}
	}

	static void printPick() {
		for (int n : pick)
			sb.append(n).append(' ');
		sb.append('\n');
	}

	public static void main(String[] args) throws IOException {
		sb.setLength(0);
		while (true) {
			st = new StringTokenizer(br.readLine());
			K = stoi(st.nextToken());
			if (K == 0)
				break;
			S = new int[K];
			for (int i = 0; i < K; i++)
				S[i] = stoi(st.nextToken());
			lotto(0, 0);
			sb.append('\n');
		}
		System.out.println(sb.toString());

	}

}