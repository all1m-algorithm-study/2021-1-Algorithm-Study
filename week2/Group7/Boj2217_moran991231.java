package main;

import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	public static void main(String[] args) throws IOException{
		int N = stoi(br.readLine());
		Integer[] ropes = new Integer[N+1];
		ropes[0]=Integer.MAX_VALUE;
		for(int i=1;i<=N; i++) ropes[i] = stoi(br.readLine());
		
		Arrays.sort(ropes, Collections.reverseOrder());
		
		int maxW =0;
		
		for(int i=1; i<=N; i++) {
			maxW = Math.max(maxW, i*ropes[i]);
		}
		
		System.out.println(maxW);
		
	}

}