package alim;

import java.util.Scanner;

public class boj4963_subln516 {
	static int w, h; 
	static int[][] map;
	static boolean[][] visit;
	static int[] dx = {0,1,1,1,0,-1,-1,-1};
	static int[] dy = {1,1,0,-1,-1,-1,0,1};
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		while(true) {
			w = sc.nextInt();
			h = sc.nextInt();
			
			if(w==0 && h==0) System.exit(0);
			
			map = new int[h][w];
			visit = new boolean[h][w];
			
			for(int i=0; i<h; i++) {
				for(int j=0; j<w; j++) {
					map[i][j] = sc.nextInt();
				}
			}
			int count = 0;
			for(int i=0; i<h; i++) {
				for(int j=0; j<w; j++) {
					if(map[i][j]==1 && visit[i][j]==false) {
						dfs(i,j);
						count++;
					}
				}
			}
			System.out.println(count);
		}
	}
		
		
	public static void dfs(int x, int y) {
		visit[x][y] = true;
			
		for(int i = 0; i<8; i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx>=0 && ny>=0 && nx<h && ny<w) {
				if(map[nx][ny]==1 && visit[nx][ny]==false) dfs(nx,ny);
				}	
			}
		}

	}


