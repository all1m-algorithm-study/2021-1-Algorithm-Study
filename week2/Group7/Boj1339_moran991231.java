

import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	static int[] coeff; // [26]
	static final int[] pow10 = { 1, 10, 100, 1_000, 10_000, 100_000, 1_000_000, 10_000_000 };

	public static void main(String[] args) throws IOException {
		coeff = new int[26];
		int N = stoi(br.readLine());
		char[][] words = new char[N][];
		for (int i = 0; i < N; i++)
			words[i] = br.readLine().toCharArray();

		for (char[] word : words) {
			int len = word.length;
			for (int i = 0; i < len; i++) {
				int ch = word[len - i - 1] - 'A';
				coeff[ch] += pow10[i];
			}
		}
		
		Arrays.sort(coeff);
		int sum=0;

		for(int i=0; i<9; i++) {
			sum += (9-i)*coeff[25-i];
		}
		System.out.println(sum);

	}

}