import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int N;
	static int[] A;

	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	public static long countSee() {
		long cnt = 0;
		int[] mul = new int[N];
		Arrays.fill(mul, 1);
		Stack<Integer> stk = new Stack<>();
//		stk.add(new Node(0));

		for (int i = 0; i < N; i++) {
			int idx;
			while (!stk.isEmpty()) {
				idx = stk.peek();
				if (A[idx] < A[i]) {
					cnt += mul[idx];
					stk.pop();
				} else if (A[idx] == A[i]) {
					cnt += mul[idx];
					mul[i] += mul[idx];
					stk.pop();
				} else {
					cnt++;
					stk.add(i);
					break;
				}
			}
			if (stk.isEmpty())
				stk.add(i);
			else if (stk.peek()!=i)
				stk.add(i);

		}

		return cnt;
	}

	public static void main(String[] args) throws IOException {
		sb.setLength(0);
		N = stoi(br.readLine());
		A = new int[N];
		for (int i = 0; i < N; i++)
			A[i] = stoi(br.readLine());

		System.out.println(countSee());
	}
}
