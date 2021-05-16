import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	
	static char[] str;
	static int stoi(String s) {
		return Integer.parseInt(s);
	}
	
	public static long solve() {
		int slen=str.length;
		Stack<Long> stack = new Stack<>();
		for(int i=0; i<slen; i++) {
			long ch = str[i];
			if(ch !=')') stack.push(ch);
			else {
				long cnt=0;
				Long popping;
				while((popping =stack.pop())  !='(') {
					if(popping<0) cnt -= popping;
					else cnt ++;
				}
				cnt *= stack.pop()-'0';
				if(cnt !=0)
					stack.push(-cnt);
			}
		}
		
		long cnt=0;
		while(!stack.isEmpty()) {
			long popping = stack.pop();
			if(popping<0) cnt-=popping;
			else cnt++;
		}
		return cnt;
	}

	public static void main(String[] args) throws IOException{
		str = br.readLine().toCharArray();
		System.out.println(solve());
	}

}