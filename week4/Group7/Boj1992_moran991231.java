import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static char[][] image;
	static final int[] dr= {0,0,1,1}, dc = {0,1,0,1};
	
	static int stoi(String s) {
		return Integer.parseInt(s);
	}
	static StringBuilder quadTree(int r, int c, int N) {
		StringBuilder sb = new StringBuilder();
		if(N==1) 
			return sb.append(image[r][c]);
			
		
		N /=2;
		StringBuilder[] sbRet = new StringBuilder[4];
		
		int [] num = new int[2];
		for(int i=0; i<4; i++) {
			sbRet[i] = quadTree(r+dr[i]*N, c+dc[i]*N, N);
			char ch = sbRet[i].charAt(0);
			if(ch == '0') num[0]++;
			else if (ch=='1') num[1]++;
		}
		
		if(num[0]==4) return sb.append(0);
		if (num[1]==4) return sb.append(1);
		sb.append('(');
		for(int i=0; i<4; i++)
			sb.append(sbRet[i].toString());
		sb.append(')');
		return sb;	
		
	}

	public static void main(String[] args) throws IOException{

		int N = stoi(br.readLine());
		image = new char[N][];
		for(int i=0;i <N; i++)
			image[i] = br.readLine().toCharArray();
		StringBuilder sb = quadTree(0,0,N);
		System.out.println(sb.toString());
		
	}

}