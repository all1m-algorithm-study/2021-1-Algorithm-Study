package alim;

import java.util.*;

public class boj15650_subln516 {
	public static int N, M;
	public static int[] arr;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		N = sc.nextInt();
		M = sc.nextInt();
		arr = new int[M];
		
		NM(1, 0);
	}
	public static void NM(int a, int b) {
		if (b == M) {
			for (int val : arr) {
				System.out.print(val + " ");
			}
			System.out.println();
			return;
		}
		
		for(int i = a; i<=N; i++) {
			arr[b] = i;
			NM(i+1, b+1);
			
		}
	}
}
