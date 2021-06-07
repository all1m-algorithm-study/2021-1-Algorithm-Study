import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int N;
	static int[][] map;
	static boolean[] height;

	static int stoi(String s) {
		return Integer.parseInt(s);
	}
	
	static int maxSafeArea() {
		int max=1;
		for(int h=1; h<=100;h++	) {
			if(!height[h]) continue;
			boolean[][] visited=new boolean[N][N];
			int cnt=0;
			for(int i=0; i<N;i++) {
				for(int j=0; j<N; j++) {
					if(map[i][j]>h&&(!visited[i][j])) {
						cnt++;
						dfs(i,j,h,visited);
					}
				}
			}
			max = Math.max(max, cnt);
		}
		return max;
	}
	
	static void dfs(int r, int c, int h, boolean[][] visited) {
		if(!(0<=r && r<N && 0<=c && c<N))
			return;
		if(map[r][c]<=h||visited[r][c])
			return;
		visited[r][c]=true;
		
		dfs(r-1,c,h,visited);
		dfs(r+1,c,h,visited);
		dfs(r,c-1,h,visited);
		dfs(r,c+1,h,visited);
		
		
	}

	public static void main(String[] args) throws IOException {
		N = stoi(br.readLine());
		map = new int[N][N];
		height=new boolean[101];
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<N;j++) {
				map[i][j] = stoi(st.nextToken());
				height[map[i][j]]=true;
			}
		}
		System.out.println(maxSafeArea());
		

	}
}
