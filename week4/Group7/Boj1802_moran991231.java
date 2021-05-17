import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static final String yes = "YES\n", no = "NO\n";
	static char[] paper;
	static int stoi(String s) {
		return Integer.parseInt(s);
	}
	
	public static String isFoldable(int s, int e) {
		if(s==e) return yes;
		for(int i=s, j=e; i<j; i++,j--) {
			if(paper[i]==paper[j])return no;
		}
		return isFoldable(s,(s+e)/2-1);
		
		
	}

	public static void main(String[] args) throws IOException{
		sb.setLength(0);
		int T = stoi(br.readLine());
		for(int t=0; t<T; t++) {
			paper = br.readLine().toCharArray();
			sb.append(isFoldable(0,paper.length-1));
		}
		System.out.println(sb.toString());
	}

}

