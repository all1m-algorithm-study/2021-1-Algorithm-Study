

import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st1, st2;
	
	static int stoi(String s) {
		return Integer.parseInt(s);
	}
	
	static int functionS(int N, int[]A, int[]B) {
		int S=0;
		for(int i=0; i<N; i++) {
			S += A[i]*B[N-i-1];
		}
		return S;
	}

	public static void main(String[] args) throws IOException{
		int N = stoi(br.readLine());
		int[] A = new int[N], B = new int[N];
		st1 = new StringTokenizer(br.readLine());
		st2 = new StringTokenizer(br.readLine());
		
		for(int i=0; i<N; i++) {
			A[i] = stoi(st1.nextToken());
			B[i] = stoi(st2.nextToken());			
		}
		Arrays.sort(A);
		Arrays.sort(B);
		
		System.out.println(functionS(N,A,B));
	}

}