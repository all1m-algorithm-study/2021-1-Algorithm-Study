package ALrim;

import java.util.*;
import java.io.*;

public class boj11724 {
	static ArrayList<Integer>[] graph;
	static boolean visited[];
	static int ans;
	
	public static void main(String[] args) throws IOException {
		int start, next;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		st = new StringTokenizer(br.readLine());
        
        int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		graph = new ArrayList[n+1];
		visited = new boolean[n+1];
		
		for (int i=1; i<n+1; i++) {
			graph[i] = new ArrayList<Integer>();
			visited[i] = false;
		}
		
		for (int i=0; i<m; i++) {
			st = new StringTokenizer(br.readLine());
			start = Integer.parseInt(st.nextToken());
			next = Integer.parseInt(st.nextToken());
			
			graph[start].add(next);
			graph[next].add(start);
		}
		
		for (int i=1; i<n+1; i++) {
			if (!visited[i]) {
				explore(i);
				ans++;
			}
		}
		
		System.out.println(ans);
        
	}
	static void explore(int start) {
		if (visited[start]) return; //explore Á¾·á
		visited[start] = true;
		
		for (int next : graph[start]) {
			if (!visited[next])
				explore(next);
		}
	}

}
