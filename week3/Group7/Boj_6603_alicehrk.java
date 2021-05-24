package today;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj_6603 {
	static String[] line;
	static boolean[] visit;
	static int n;
	
	private static void dfs(int v, int d) throws IOException {
		if(d == 6) {
			String str = "";
			for(int i = 1; i <= n; i++) {
				if(visit[i]) str += line[i] + " ";
			}
			System.out.println(str);
			return;
		}
		
		for(int i = v; i <= n; i++) {
			visit[i] = true;
			dfs(i + 1, d + 1);
			visit[i] = false;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		while(true) {
			line = br.readLine().split("\\s");
			System.out.println();
			n = Integer.parseInt(line[0]); visit = new boolean[n+1];
			
			if(n == 0) break;			
			dfs(1, 0); System.out.println();
		}
	}
}
