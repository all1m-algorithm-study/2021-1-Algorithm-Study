import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int N,M;
	static int[] A,B;
	
	static int stoi(String s) {
		return Integer.parseInt(s);
	}
	
	public static void mySort() {
		int ai=0, bi=0;
		
		while(ai<N && bi<M) {
			if(A[ai]<=B[bi]) {
				sb.append(A[ai]);
				ai++;
			}else {
				sb.append(B[bi]);
				bi++;
			}
			sb.append(' ');
		}
		
		if(bi<M) {
			int[] temp=A;
			A=B;
			B=temp;
			ai=bi;
			N=M;
		}
		for(int i=ai; i<N; i++) 
			sb.append(A[i]).append(' ');
			
		
		
		
	}

	public static void main(String[] args) throws IOException{
		sb.setLength(0);
		st = new StringTokenizer(br.readLine());
		N = stoi(st.nextToken());
		M = stoi(st.nextToken());
		A = new int[N];
		B = new int[M];
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; i++)
			A[i] = stoi(st.nextToken());

		st = new StringTokenizer(br.readLine());
		for(int i=0; i<M;i++)
			B[i] = stoi(st.nextToken());
		
		mySort();
		System.out.println(sb.toString());
	}

}

