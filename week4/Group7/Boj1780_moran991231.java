import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int N;
	static byte[][] paper;
	static final int[] dr = { 0, 0, 0, 1, 1, 1, 2, 2, 2 };
	static final int[] dc = { 0, 1, 2, 0, 1, 2, 0, 1, 2 };
	static int[] cnt;

	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	static byte divide(int r, int c, int n) {
		if (n == 1)
			return paper[r][c];
		n /= 3;
		int[] ret= new int[3];
		for(int i=0; i<9; i++) {
			byte temp = divide(r+dr[i]*n, c+dc[i]*n,n);
			if(temp == -1) continue;
			ret[temp] ++;			
		}
		
		for(int i=0; i<3; i++)
			if(ret[i]==9)
				return (byte) i;
			else
				cnt[i]+=ret[i];
				
		return -1;

	}

	public static void main(String[] args) throws IOException {
		N = stoi(br.readLine());
		paper = new byte[N][N];
		cnt = new int[3];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				paper[i][j] = (byte) (Byte.parseByte(st.nextToken())+1);
			}
		}
		int ret=divide(0,0,N);
		if(ret>=0) cnt[ret]++;
		for(int i:cnt)
			System.out.println(i);

	}

}