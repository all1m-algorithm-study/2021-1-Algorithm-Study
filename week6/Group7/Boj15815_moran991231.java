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
		char[] state = br.readLine().toCharArray();
		
		Stack<Integer> stk = new Stack<Integer>();
		
		for(char ch: state) {
			if('0'<=ch && ch<='9') {
				stk.push(ch-'0');
				continue;
			}
			int y= stk.pop(), x = stk.pop();
			
			if(ch =='+')
				x+=y;
			else if (ch=='-')
				x -=y;
			else if (ch=='*')
				x*=y;
			else
				x /=y;
			stk.push(x);
			
		}
		System.out.println(stk.pop());

	}
}
