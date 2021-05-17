import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	final static String COMMA = ", ";

	static int stoi(String s) {
		return Integer.parseInt(s);
	}


	static void josephus(int n, int k) {
		sb.append('<');
		Queue<Integer> que = new LinkedList<>();
		for(int i=1; i<=n; i++)
			que.add(i);
		
		while(que.size()>1) {
			for(int i=0; i<k-1;i++) 
				que.add(que.remove());
			sb.append(que.remove()).append(COMMA);
		}
		sb.append(que.remove()).append('>');
		
		
	}
	public static void main(String[] args) throws IOException {
		sb.setLength(0);
		st = new StringTokenizer(br.readLine());
		int n = stoi(st.nextToken()), k = stoi(st.nextToken());
		josephus(n,k);
		System.out.println(sb.toString());

	}
}
