import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	
	static int N;
	static int[][] mat;
	static final int[] dr = {0,1,0,1}, dc = {0,0,1,1};
	
	static int stoi(String s) {
		return Integer.parseInt(s);
	}
	
	static int getUnderBoss(int[][]m, int r, int c) {
		PriorityQueue<Integer>pq = new PriorityQueue<>(Collections.reverseOrder());
		for(int i=0; i<4; i++)
			pq.add(m[r+dr[i]][c+dc[i]]);
		pq.remove();
		return pq.remove();
	}
	
	static int myPooling(int[][]m, int len) {
		if(len==1)
			return m[0][0];
		
		len /=2;
		int[][] ret = new int[len][len];
		for(int i=0; i<len; i++) {
			for(int j=0; j<len;j++) {
				ret[i][j] = getUnderBoss(m,i*2,j*2);
			}
		}
		m=null;
		return myPooling(ret,len	);
		
		
	}

	public static void main(String[] args) throws IOException{
		sb.setLength(0);
		N = stoi(br.readLine());
		mat = new int[N][N];
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<N; j++)
				mat[i][j] = stoi(st.nextToken());
		}
		int ret=myPooling(mat,N);
		System.out.println(ret);
		
	}

}

