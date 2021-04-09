

import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	public static void main(String[] args) throws IOException {
		int[] pipe = new int[1001]; // {0,0,0,0,...}
		
		// input
		st = new StringTokenizer(br.readLine());
		int N = stoi(st.nextToken());
		int L = stoi(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++)
			pipe[stoi(st.nextToken())] = 1;

		// taping
		int cnt = 0;
		for (int p = 1; p <= 1000; p++) {
			if (pipe[p] == 1) {
				cnt++;
				p = p + L - 1; // skip the section p ~ p+L-1
			}
		}

		System.out.println(cnt);
	}

}