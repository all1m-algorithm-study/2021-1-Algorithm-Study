
import java.io.*;
import java.util.*;

class Boj_2231_ {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	
	static int digitGen(int x) {
		int ret = x;
		while(x!=0) {
			ret += x%10;
			x/=10;
		}
		return ret;
	}
	
	static int getDigits(int x) {
		int digit=0;
		while(x!=0) {
			x /=10;
			digit++;
		}
		return digit;
	}
	
	static int getMinGenerator(int N) {
		
		
		int digit = getDigits(N);
		int temp = Math.max(1, N-9*digit);
		for(int i= temp; i<=N; i++) {
			if(N == digitGen(i)) return i;
		}
		
		return 0;
		
	}
	public static void main(String[] args) throws IOException{
		
		int N = stoi(br.readLine());
		System.out.println(getMinGenerator(N));
		
	}

}