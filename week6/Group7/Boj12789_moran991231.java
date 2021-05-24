import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	public static void main(String[] args) throws IOException {
		sb.setLength(0);
		Queue<Integer> q = new LinkedList<>();
		Stack<Integer> stk = new Stack<>();
		int N = stoi(br.readLine());
		st = new StringTokenizer(br.readLine());

		for (int i = 0; i < N; i++)
			q.add(stoi(st.nextToken()));

		int next = 1;
		boolean snack = true;
		while (next <= N) {
			if (!q.isEmpty()) {
				if (q.peek() == next) {
					q.remove();
					next++;
					continue;
				}
			}
			if (!stk.isEmpty()) {
				if (stk.peek() == next) {
					stk.pop();
					next++;
					continue;
				}
			}
			while (true) {
				if (q.isEmpty()) {
					snack = false;
					break;
				}
				int x = q.remove();
				if (x == next) {
					next++;
					break;
				} else
					stk.push(x);
			}
			
			if (!snack)
				break;

		}

		System.out.println(snack ? "Nice" : "Sad");
	}
}
