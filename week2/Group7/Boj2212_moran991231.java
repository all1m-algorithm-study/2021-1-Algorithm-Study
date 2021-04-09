

import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	public static void main(String[] args) throws IOException {
		int N = stoi(br.readLine());
		int K = stoi(br.readLine());

		if (N <= K) {
			System.out.println(0);
			return;
		}

		int[] P = new int[N];
		Integer[] D = new Integer[N - 1];

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++)
			P[i] = stoi(st.nextToken());
		Arrays.sort(P);
		for (int i = 0; i < N - 1; i++)
			D[i] = P[i + 1] - P[i];
		Arrays.sort(D, Collections.reverseOrder());

		int totalD = P[N - 1] - P[0];
		for (int k = 0; k < K - 1; k++)
			totalD -= D[k];

		System.out.println(totalD);

	}

}