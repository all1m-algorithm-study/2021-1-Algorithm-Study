import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int N;
	static char[][] paper;
	static final int[] dr = {0,0,1,1},dc= {0,1,0,1};
	static int zeros,ones;
	
	static int stoi(String s) {
		return Integer.parseInt(s);
	}
	
	public static char cut(int r, int c, int len) {
		if(len==1)
			return paper[r][c];
		
		len /=2;
		int z=0, o=0;
		for(int i=0; i<4; i++) {
			char ch = cut(r+dr[i]*len,c+dc[i]*len,len);
			if(ch=='0')
				z++;
			else if (ch=='1')
				o++;
		}
		if(z==4)
			return '0';
		else if (o==4)
			return '1';
		else {
			zeros+=z;
			ones+=o;
		}
		return 0;		
		
	}

	public static void main(String[] args) throws IOException{
		sb.setLength(0);
		N = stoi(br.readLine());
		paper = new char[N][N];
		
		for(int i=0; i<N; i++){
			String str = br.readLine();
			for(int j=0; j<N; j++)
				paper[i][j] = str.charAt(j*2);
		}
		char ch = cut(0,0,N);
		if(ch=='0')
			zeros++;
		else if (ch=='1')
			ones++;
		System.out.println(zeros);
		System.out.println(ones);
		
		
	}

}

