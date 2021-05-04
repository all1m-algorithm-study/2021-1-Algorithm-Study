
import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	
	static final int LEN = 46;
	static int[] tri = new int[LEN];
	
	static int stoi(String s) {
		return Integer.parseInt(s);
	}
	
	static void makeTri() {
		tri[0]=1;
		for(int i=1; i<LEN; i++)
			tri[i] = i*(i+1)/2;
	}
	static int isUreka(int N) {
		for(int i=1; i<LEN; i++) {
			for(int j=i; j<LEN; j++) {
				for(int k=j; k<LEN; k++) {
					if(N <tri[i]) break;
					if(N == tri[i]+tri[j]+tri[k]) return 1;
				}
			}
		}
		return 0;
	}

	public static void main(String[] args) throws IOException{
		if(tri[0]==0) makeTri();
		sb.setLength(0);
		int T = stoi(br.readLine());
		for(int t=0; t<T; t++) {
			int N = stoi(br.readLine());
			sb.append(isUreka(N)).append('\n');
		}
		System.out.print(sb.toString());
		
	}

}