import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int N;
	static int[] A, NGE;
	

	static int stoi(String s) {
		return Integer.parseInt(s);
	}
	
	public static void findNGE() {
		Stack<Integer> stk = new Stack<>();
		stk.add(0);
		for(int i=1; i<N;i++) {
			while(!stk.isEmpty()) {
				int top = stk.peek();
				if(A[top]<A[i]) {
					NGE[top]=A[i];
					stk.pop();
				}else
					break;
				
			}
			stk.add(i);
		}
		
		while(!stk.isEmpty()) {
			int popping = stk.pop();
			NGE[popping]=-1;
		}
	}


	public static void main(String[] args) throws IOException {
		sb.setLength(0);
		N = stoi(br.readLine());
		st = new StringTokenizer(br.readLine());
		A = new int[N];
		NGE = new int[N];
		for(int i=0; i<N;i++)
			A[i] = stoi(st.nextToken());
		findNGE();
		for(int nge:NGE)
			sb.append(nge).append(' ');
		System.out.println(sb.toString());
		
	}
}
