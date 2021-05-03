
import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	static int N, S;
	static int[] A;
	static int[] maskArr = new int[20];

	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	static int countCases() {
		if (maskArr[0] == 0)
			for (int i = 0; i < 20; i++)
				maskArr[i] = 1 << i;

		int wholeMask = (1 << N) - 1, key = 1;
		int cnt = 0,sum=0;
		while (key != 0) {
			
			sum=0;
			for(int i=0; i<N; i++) {
				if((key&maskArr[i] )!=0) sum += A[i];
			}
			if(sum == S) cnt++;
			key = (key+1)&wholeMask;
		}
		return cnt;
	}

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		N = stoi(st.nextToken());
		S = stoi(st.nextToken());
		A = new int[N];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++)
			A[i] = stoi(st.nextToken());
		
		System.out.println(countCases());

	}

}