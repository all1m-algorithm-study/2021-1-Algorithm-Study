import java.io.*;
import java.util.*;
 class Main {
	 static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	 static StringTokenizer st;
	 static StringBuffer sb = new StringBuffer();
	 
	 static int N;
	 static long B;
	 static int[][]A;
	 static final int MOD = 1000;
	 static int stoi(String s) {
		 return Integer.parseInt(s);
	 }
	 
	 public static int[][] MatDot(int[][] m1, int[][]m2){
		 int[][] ret = new int[N][N];
		 for(int i=0; i<N; i++) {
			 for(int j=0; j<N;j++) {
				 for(int k=0; k<N;k++) {
					 ret[i][j] +=(m1[i][k]*m2[k][j]);
					 ret[i][j] %=MOD;
				 }
			 }
		 }
		 return ret;
	 }
	 
	 public static int[][] func(int[][]mat, long pow){
		 if(pow==1)return mat;
		 
		 int[][ ]temp = func(mat,pow/2);
		 temp = MatDot(temp,temp);
		 if(pow%2==0)
			 return temp;
		 else
			 return MatDot(temp,mat);
	 }
	 public static void main(String[] args)throws IOException {
		 sb.setLength(0);
		 st = new StringTokenizer(br.readLine());
		 N = stoi(st.nextToken());
		 B = Long.parseLong(st.nextToken());
		 
		 A = new int[N][N];
		 for(int i=0; i<N; i++) {
			 st = new StringTokenizer(br.readLine());
			 for(int j=0; j<N;j++)
				 A[i][j] = stoi(st.nextToken())%MOD;
		 }
		 int[][] ret = func(A,B);
		 for(int i=0; i<N; i++) {
			 for(int j=0; j<N;j++)
				 sb.append(ret[i][j]).append(' ');
			 sb.append('\n');
		 }
		 System.out.println(sb.toString());
			 
	 }
	 
}
