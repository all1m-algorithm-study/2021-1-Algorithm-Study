import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	
	static int N, M;
	static int[]selected;
	
	static int stoi(String s) {
		return Integer.parseInt(s);
	}
	static void printSelected() {
		for(int n:selected)
			sb.append(n).append(' ');
		sb.append('\n');
	}
	static void dfs(int start, int cnt) {
		if(cnt==M) {
			printSelected();
			return;
		}
		
		for(int i=start; i<=N; i++) {
			selected[cnt]=i;
			dfs(i+1, cnt+1);
		}
		return;
	}

	public static void main(String[] args) throws IOException{
		sb.setLength(0);
		st = new StringTokenizer(br.readLine());
		N = stoi(st.nextToken());
		M = stoi(st.nextToken());
		selected = new int[M];
		
		dfs(1,0);
		System.out.println(sb.toString());
		
	}

}