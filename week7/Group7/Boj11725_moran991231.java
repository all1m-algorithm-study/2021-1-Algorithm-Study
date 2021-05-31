import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	static int N;
	static ArrayList<Integer>[] edges;
	static int[] parentOf;
	static int stoi(String s) {
		return Integer.parseInt(s);
	}
	
	static void dfs(int root) {
		for(int next: edges[root]) {
			if(parentOf[next]==0) {
				parentOf[next]=root;
				dfs(next);
			}
		}
	}

	public static void main(String[] args) throws IOException {
		sb.setLength(0);
		N = stoi(br.readLine());
		edges = new ArrayList[N+1];
		parentOf = new int[N+1];
		for(int i=1; i<=N;i++)
			edges[i] = new ArrayList<Integer>();
		
		for(int i=0; i<N-1;i++) {
			st = new StringTokenizer(br.readLine());
			int a = stoi(st.nextToken()), b= stoi(st.nextToken());
			edges[a].add(b);
			edges[b].add(a	);
		}

		parentOf[1]=-1;
		dfs(1);
		
		for(int i=2; i<=N;i++)
			sb.append(parentOf[i]).append('\n');
		System.out.println(sb.toString());
		
	}
}
