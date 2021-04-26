 

import java.io.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();

	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	static void hanoi(int h, int from, int to, int temp) {
		if (h == 1) {
			sb.append(from).append(' ').append(to).append('\n');
			return;
		}
		hanoi(h-1,from,temp,to);
		hanoi(1, from, to, temp);
		hanoi(h - 1, temp, to, from);
	}

	public static void main(String[] args) throws IOException {
		sb.setLength(0);
		int N = stoi(br.readLine());
		sb.append((1 << N) - 1).append('\n'); // K
		
		hanoi(N,1,3,2);
		System.out.print(sb.toString());
	}

}