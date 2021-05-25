package alim;
import java.util.*;

public class boj2630_subln516 {
	public static int N, white=0, blue=0;
	public static int[][] arr;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		N=sc.nextInt();
		arr=new int[N][N];
		for(int i = 0; i<N; i++) {
			for(int j = 0; j<N; j++)
				arr[i][j] = sc.nextInt();
		}
		find(N,0,0);
		System.out.println(white);
		System.out.println(blue);
	}
	public static void find(int N, int row, int col) {
		for(int i = row; i<N+row; i++) {
			for(int j = col; j<N+col; j++) {
				if(arr[i][j] != arr[row][col]) {
					find(N/2, row, col);
					find(N/2, row, col + N/2);
					find(N/2, row + N/2, col);
					find(N/2, row + N/2, col + N/2);
					return;
				}
			}
		}
		if(arr[row][col] == 0) white++;
		else blue++;
	}
}
