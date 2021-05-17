import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	public static int solve(char[] str) {
		Stack<Integer> stk = new Stack<>();
		int len = str.length;
		if (len % 2 == 1)
			return 0;

		for (int ch : str) {

			if (ch == '(' || ch == '[')
				stk.push(ch);

			else if (ch == ')') {
				int point = 0;
				while (!stk.isEmpty()) {
					int popping = stk.pop();
					if (popping < 0)
						point -= popping;
					else if (popping == '(') {
						stk.push(point == 0 ? -2 : -2 * point);
						break;
					} else
						return 0;

				}

			} else if (ch == ']') {
				int point = 0;
				while (!stk.isEmpty()) {
					int popping = stk.pop();
					if (popping < 0)
						point -= popping;
					else if (popping == '[') {
						stk.push(point == 0 ? -3 : -3 * point);
						break;
					} else
						return 0;

				}
			}
		}

		int val = 0;
		while (!stk.isEmpty()) {
			int popping = stk.pop();
			if (popping >= 0)
				return 0;
			val -= popping;
		}
		return val;
	}

	public static void main(String[] args) throws IOException {
		char[] str = br.readLine().toCharArray();
		System.out.println(solve(str));

	}
}
