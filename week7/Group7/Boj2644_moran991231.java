import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	static int N, X,Y,M;
	static boolean[] visited;
	static ArrayList<Integer>[] rel;
	static int stoi(String s) {
		return Integer.parseInt(s);
	}
	
	public static int dfs(int cur, int chon) {
		if(cur==Y)
			return chon;
		chon++;
		visited[cur]=true;
		for(int next: rel[cur]) {
			if(!visited[next]){
				int ret = dfs(next,chon);
				if(ret>0)return ret;
			}
		}
		return 0;
	}
	

	public static void main(String[] args) throws IOException {
		sb.setLength(0);
		N = stoi(br.readLine());
		st = new StringTokenizer(br.readLine());
		X = stoi(st.nextToken());
		Y = stoi(st.nextToken());
		M = stoi(br.readLine());
		
		visited = new boolean[N+1];
		rel = new ArrayList[N+1];
		for(int i=1; i<=N;i++)
			rel[i] = new ArrayList<>();
		
		for(int i=0; i<M;i++) {
			st = new StringTokenizer(br.readLine());
			int a = stoi(st.nextToken()), b = stoi(st.nextToken());
			rel[a].add(b);
			rel[b].add(a);
		}
		
		int ret =dfs(X,0);
		if(X!=Y&&ret==0)
			ret=-1;
		System.out.println(ret);

	}
}
