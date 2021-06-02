import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	
	static int R,C;
	static char[][] map;
	static int max=1;
	static boolean[] used;
	

	static int stoi(String s) {
		return Integer.parseInt(s);
	}
	
	static void backTracking(int r, int c, int depth) {
		if(!(0<=r&&r<R && 0<=c && c<C))
			return;
		int ch = map[r][c]-'A';
		if(used[ch])
			return;
		if(depth>max)
			max=depth;
		used[ch]=true;
		depth++;
		backTracking(r-1,c,depth);
		backTracking(r+1,c,depth);
		backTracking(r,c-1,depth);
		backTracking(r,c+1,depth);
		used[ch]=false;
		
	}
	

	public static void main(String[] args) throws IOException {
		sb.setLength(0);
		st = new StringTokenizer(br.readLine());
		R = stoi(st.nextToken());
		C= stoi(st.nextToken());
		map = new char[R][];
		for(int i=0; i<R;i++)
			map[i]	=br.readLine().toCharArray();
		max=0;
		used = new boolean[26];
		backTracking(0,0,1);
		System.out.println(max);
	}
}
