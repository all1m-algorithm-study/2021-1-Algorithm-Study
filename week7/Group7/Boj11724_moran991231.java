import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	
	static int N,M;
	static ArrayList<Integer>[] edges;

	static int stoi(String s) {
		return Integer.parseInt(s);
	}
	static int countConnected() {
		
		int cnt=0;
		boolean[] visited  = new boolean[N+1];
		for(int i=1; i<=N;i++) {
			if(visited[i])continue;
			cnt++;
			Queue<Integer> q = new LinkedList<Integer>();
			q.add(i);
			while(!q.isEmpty()) {
				int cur = q.remove();
				if(visited[cur]) continue;
				visited[cur]=true;
				for(int next: edges[cur])
					q.add(next);
			}
		}
		
		
		return cnt;
	}

	public static void main(String[] args) throws IOException {
		sb.setLength(0);
		st = new StringTokenizer(br.readLine());
		N = stoi(st.nextToken());
		M = stoi(st.nextToken());
		
		edges= new ArrayList[N+1];
		for(int i=1;i<=N;i++)
			edges[i] = new ArrayList<Integer>();
		
		for(int i=0; i<M;i++) {
			st = new StringTokenizer(br.readLine());
			int a = stoi(st.nextToken()), b = stoi(st.nextToken());
			edges[a].add(b);
			edges[b].add(a);
		}
		
		System.out.println(countConnected());
		

	}
}
