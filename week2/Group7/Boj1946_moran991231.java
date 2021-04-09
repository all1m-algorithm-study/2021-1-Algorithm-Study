
import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	static int countFresmen(int[] apps, int N) {
		int cnt = 0;
		int min = Integer.MAX_VALUE;
		for (int i = 1; i <= N; i++) {
			if (apps[i] < min) {
				cnt++;
				min = apps[i];
			}
		}
		return cnt;
	}

	public static void main(String[] args) throws IOException {
		sb.setLength(0);
		int T = stoi(br.readLine());
		for (int t = 0; t < T; t++) {
			int N = stoi(br.readLine());
			int[] apps = new int[N + 1];
			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				apps[stoi(st.nextToken())] = stoi(st.nextToken());
			}
			sb.append(countFresmen(apps, N)).append('\n');

		}
		System.out.println(sb.toString());

	}

}