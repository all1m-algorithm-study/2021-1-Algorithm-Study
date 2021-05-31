import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int N;
	static int[] partnerOf;

	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	public static int solve() {
		int[] visited = new int[N + 1];

		for (int i = 1; i <= N; i++) {
			if (visited[i] == 0) {
				if(i==partnerOf[i])
					visited[i]=i;
				else dfs(i, i, visited);

			}
		}
		int cnt = 0;
		for (int i = 1; i <= N; i++)
			if (visited[i] <= 0)
				cnt++;
		return cnt;
	}

	public static int dfs(int x, int start, int[] visited) {
		if (visited[x] == start)
			return x;
		else if (visited[x] !=0)
			return -1;
			

		visited[x] = start;
		int ret = dfs(partnerOf[x], start, visited);
		visited[x]=ret;
		return (ret==x||ret<0)? -1:ret;
		
	}

	public static void main(String[] args) throws IOException {
		sb.setLength(0);
		int T = stoi(br.readLine());
		for (int t = 0; t < T; t++) {
			N = stoi(br.readLine());
			partnerOf = new int[N + 1];
			st = new StringTokenizer(br.readLine());
			for (int i = 1; i <= N; i++)
				partnerOf[i] = stoi(st.nextToken());

			sb.append(solve()).append('\n');
		}

		System.out.println(sb.toString());
	}
}
