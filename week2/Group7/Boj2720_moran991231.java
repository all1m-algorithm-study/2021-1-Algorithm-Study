package done;

import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	
	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	public static void main(String[] args) throws IOException{
		sb.setLength(0);
		int T = stoi(br.readLine());
		for(int i=0; i<T; i++) {
			int C = stoi(br.readLine());
			
			sb.append(C/25).append(' ');
			C %= 25;
			sb.append(C/10).append(' ');
			C%=10;
			sb.append(C/5).append(' ');
			C%=5;
			sb.append(C).append('\n');
		}
		System.out.println(sb.toString());
	}

}