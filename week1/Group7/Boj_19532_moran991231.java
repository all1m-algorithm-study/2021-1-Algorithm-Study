
import java.io.*;
import java.util.*;

class Boj_19532 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	public static void main(String[] args) throws IOException{
		int a,b,c,d,e,f;
		st = new StringTokenizer(br.readLine());
		a=stoi(st.nextToken());
		b=stoi(st.nextToken());
		c=stoi(st.nextToken());
		d=stoi(st.nextToken());
		e=stoi(st.nextToken());
		f=stoi(st.nextToken());
		
		int denominator = a*e-b*d;
		int x = (c*e-b*f)/denominator;
		int y = (a*f-c*d)/denominator;
		
		System.out.printf("%d %d\n", x,y);
	}

}