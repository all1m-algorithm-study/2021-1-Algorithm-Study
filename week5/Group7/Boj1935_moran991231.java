import java.io.*;
import java.util.*;

 class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static int[] AZ;
	static int stoi(String s) {
		return Integer.parseInt(s);
	}
	
	public static double calc(char[] state) {
		Stack<Double>stk = new Stack<>();
		for(char ch: state) {
			if('A'<=ch && ch<='Z')
				stk.add((double)AZ[ch-'A']);
			else {
				double y = stk.pop(),x=stk.pop();
				if(ch == '+')
					x +=y;
				else if (ch=='-')
					x -=y;
				else if(ch == '*')
					x *=y;
				else
					x /=y;
				stk.add(x);
			}
		}
		
		return stk.pop();
	}
	
	public static void main(String[] args) throws IOException {
		int N = stoi(br.readLine());
		AZ = new int[26];
		char[]state = br.readLine().toCharArray();
		for(int i=0; i<N;i++) 
			AZ[i]=stoi(br.readLine());
		
		System.out.printf("%.2f\n",calc(state));
		
	}
}
