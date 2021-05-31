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
	
	static int countGuests() {
		Queue<Integer> q = new LinkedList<Integer>();
		int visited[] = new int[N+1];
		Arrays.fill(visited, Integer.MAX_VALUE);
		q.add(1);
		visited[1]=0;
		while(!q.isEmpty()) {
			int cur = q.remove();
			int temp=visited[cur]+1;
			for(int next:edges[cur]) {
				if(temp<visited[next]) {
					visited[next]=temp;
					q.add(next);
				}
			}
		}
		int cnt=-1;
		for(int v:visited)
			if(v<=2) cnt++;
		return cnt;
	}

	public static void main(String[] args) throws IOException {
		sb.setLength(0);
		
		N = stoi(br.readLine());
		M = stoi(br.readLine());
		
		edges = new ArrayList[N+1];
		for(int i=1; i<=N;i++)
			edges[i] = new ArrayList<>();
		
		for(int i=0; i<M;i++) {
			st = new StringTokenizer(br.readLine());
			int a = stoi(st.nextToken()),b=stoi(st.nextToken());
			edges[a].add(b);
			edges[b].add(a);
		}
		System.out.println(countGuests());
		
		
	}
}
