import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int N,M;
	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	public static void main(String[] args) throws IOException{
		sb.setLength(0);
		st = new StringTokenizer(br.readLine());
		N = stoi(st.nextToken());
		M = stoi(st.nextToken());
		ArrayList<Integer> rq = new ArrayList<>(N);
		for(int i=1; i<=N; i++)
			rq.add(i);
		int cur=0;
		 int count=0;
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<M; i++) {
			int target = stoi(st.nextToken());
			int idx = rq.indexOf(target);
			
			int l,r;
			if(cur<idx) {
				l = idx-cur;
				r = N+cur-idx;
				
			}else {
				r = cur-idx;
				l = N+idx-cur;
			}
			
			count += Math.min(l, r);
			cur=idx;
			rq.remove(cur);
			N--;
		}
		
		System.out.println(count);
		
	}

}

