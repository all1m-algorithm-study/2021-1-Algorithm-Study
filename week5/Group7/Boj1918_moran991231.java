import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	static boolean isPrior(char op1, char op2) { // a<b일 때 true
		int a, b;
		if (op1 == '(')
			a = 0;
		else if (op1 == '+' || op1 == '-')
			a = 1;
		else
			a = 2;
		if (op2 == '(')
			b = 0;
		else if (op2 == '+' || op2 == '-')
			b = 1;
		else
			b = 2;

		if (a >= b)
			return true;
		else
			return false;

	}

	public static void func(char[] state) {
		Stack<Character> stk = new Stack<>();

		for (char ch : state) {
			if ('A' <= ch && ch <= 'Z')
				sb.append(ch);
			else {
				if (ch == ')') {
					char popping;
					while ((popping = stk.pop()) != '(')
						sb.append(popping);
				} else if (ch == '(') {
					stk.add(ch);

				} else if (stk.isEmpty())
					stk.add(ch);

				else if (isPrior(stk.peek(), ch)) {
					while((!stk.isEmpty()) &&isPrior(stk.peek(), ch) ) {
						sb.append(stk.pop());
					}
					stk.add(ch);
				} else {
					stk.add(ch);
				}

			}
		}

		while (!stk.isEmpty())
			sb.append(stk.pop());

	}

	public static void main(String[] args) throws IOException {
		sb.setLength(0);
		char[] state = br.readLine().toCharArray();
		func(state);
		System.out.println(sb.toString());

	}
}
