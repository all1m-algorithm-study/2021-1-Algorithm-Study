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
		int[] chus = new int[N];
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; i++)
			chus[i] = stoi(st.nextToken());
		
		Arrays.sort(chus);
		
		if(chus[0]>1) {
			System.out.println(1);
			return;
		}
		
		int max=1;
		for(int i=1; i<N; i++) {
			if(chus[i]<=max+1) {
				max += chus[i];
			}
		}
		System.out.println(max+1);
		
	}

}