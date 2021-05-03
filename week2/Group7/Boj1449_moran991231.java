

import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	public static void main(String[] args) throws IOException {
		// input
		st = new StringTokenizer(br.readLine());
		int N = stoi(st.nextToken()); // the number of holes
		int L = stoi(st.nextToken()); // the length of a tape
		int[] holes = new int[N]; // positions of holes
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++)
			holes[i] = stoi(st.nextToken());

		// sort
		Arrays.sort(holes);

		// taping
		int taped = 0, cnt = 0;
		for (int x : holes) { // same with "for x in holes: " in python

			if (taped < x) {
				// if the hole is untaped
				cnt++;
				taped = x + L - 1;
			}
		}

		System.out.println(cnt);
	}

}