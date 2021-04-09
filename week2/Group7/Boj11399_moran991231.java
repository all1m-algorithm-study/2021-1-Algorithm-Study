package main;

import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	public static void main(String[] args) throws IOException{
		int N = stoi(br.readLine());
		
		int[] P = new int[N];
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; i++) 
			P[i] = stoi(st.nextToken());		
		Arrays.sort(P);
		
		int time=0;
		
		for(int i=0; i<N; i++)
			time += (N-i)*P[i];
		
		System.out.println(time);
	}

}