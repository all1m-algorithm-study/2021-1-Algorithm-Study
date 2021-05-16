import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	static void fillStr(char[] str, int start, int end) {
		for (int i = start; i < end; i++)
			str[i] = ' ';
	}

	static void cantor(char[] str, int start, int N) {
		if (N == 0)
			return;
		N /= 3;

		fillStr(str, start + N, start + N + N);
		Arrays.fill(str, start + N, start + N * 2,' ');
		cantor(str, start, N);
		cantor(str, start + N * 2, N);
	}

	static void printStr(char[] str) {
		sb.append(str);
		sb.append('\n');
	}

	public static void main(String[] args) throws IOException {
		sb.setLength(0);
		String s;
		while ((s = br.readLine()) != null) {
			if (s.length() == 0)
				break;
			int k = stoi(s);
			int N = 1;
			for (int i = 0; i < k; i++)
				N *= 3;

			char[] str = new char[N];
			Arrays.fill(str, '-');

			cantor(str, 0, N);
			printStr(str);
		}
		System.out.println(sb.toString());

	}

}