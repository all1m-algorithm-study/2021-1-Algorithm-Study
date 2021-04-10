
import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int stoi(String s) {
		return Integer.parseInt(s);
	}
	
	public static long ApowerB(long A,long B, long C) {
		if(B==0) return 1;
		long temp = ApowerB(A,B/2,C);
		temp = (temp*temp)%C;
		if(B%2==0) return temp;
		else return(temp*A)%C;
		
	}

	public static void main(String[] args) throws IOException{
		st = new StringTokenizer(br.readLine());
		long A = stoi(st.nextToken()), B = stoi(st.nextToken()), C = stoi(st.nextToken());
		A %=C;		
		System.out.println(ApowerB(A,B,C));
	}

}