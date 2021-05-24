import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	static int N, M;
	static Computer[] coms;

	static class Computer {
		boolean infected = false;
		ArrayList<Integer> edges = new ArrayList<Integer>();

		void add(int x) {
			edges.add(x);
		}
	}

	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	static int infectComs() {
		Queue<Computer> q = new LinkedList<>();

		q.add(coms[1]);
		
		while (!q.isEmpty()) {
			Computer com = q.remove();
			if (com.infected)
				continue;
			com.infected = true;
			for (int next : com.edges)
				if (!coms[next].infected)
					q.add(coms[next]);

		}

		int cnt = -1;
		for (int i = 1; i <= N; i++)
			cnt += coms[i].infected ? 1 : 0;
		return cnt;
	}

	public static void main(String[] args) throws IOException {
		sb.setLength(0);
		N = stoi(br.readLine());
		M = stoi(br.readLine());

		coms = new Computer[N + 1];
		for (int i = 1; i <= N; i++)
			coms[i] = new Computer();

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int a = stoi(st.nextToken()), b = stoi(st.nextToken());
			coms[a].add(b);
			coms[b].add(a);
		}

		System.out.println(infectComs());
		
	}
}
