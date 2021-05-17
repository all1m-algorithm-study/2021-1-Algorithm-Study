import java.io.*;
 class Main {
	 static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	 static int stoi(String s) {
		 return Integer.parseInt(s);
	 }
	 static int A,N;
	 static long L,R;
	 
	static final int[][] next = {{0,2,1},{1,0,0},{1,2,1}};
	static int[][][] tree=null;
	static int[] cnt;
	static long[] pow3 = new long[21];
	
	static void makeTree() {
		pow3[0]=1;
		for(int i=1; i<21; i++)
			pow3[i] = pow3[i-1]*3;
		tree = new int[3][21][3];
		for(int i=0; i<3;i++)
			tree[i][0][i]=1;
		for(int n=1; n<21;n++) {
			for(int x=0; x<3; x++) {
				for(int y:next[x]) {
					tree[x][n][0]+=tree[y][n-1][0];
					tree[x][n][1]+=tree[y][n-1][1];
					tree[x][n][2]+=tree[y][n-1][2];
				}
			}
		}
		return;
	}
	
	static void func(int root, int n,long l, long r) {
		long pow3n = pow3[n];
		if((l<0 && r<0) || (pow3n<=l && pow3n<=r))	
			return;
		if(l<0)l=0;
		if(r>=pow3n) r= pow3n-1;
		
		if(l==0 && r>=pow3n-1) {
			cnt[0] += tree[root][n][0];
			cnt[1] += tree[root][n][1];
			cnt[2] += tree[root][n][2];
			
			return;
		}
		
		pow3n /=3;
		n--;
		func(next[root][0],n,l,r);
		
		l -= pow3n;
		r -= pow3n;
		func(next[root][1],n,l,r);
		
		l -= pow3n;
		r -= pow3n;
		func(next[root][2],n,l,r);
		
		
	}
	 
	 public static void main(String[] args)throws IOException{
		 if(tree == null)
			 makeTree();
		 cnt = new int[3];
		 A = stoi(br.readLine())-1;
		 L = stoi(br.readLine());
		 R = stoi(br.readLine());
		 N = stoi(br.readLine());
		 
		 func(A,N,L,R	);
		 System.out.printf("%d %d %d \n",cnt[0],cnt[1],cnt[2]	);
		 
		 
	 }
}
