

import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	static int stoi(String s) {
		return Integer.parseInt(s);
	}
	

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		int N = stoi(st.nextToken()), M = stoi(st.nextToken());
		PriorityQueue<Long> minHeap = new PriorityQueue<>();

		st = new StringTokenizer(br.readLine());
		
		long sum=0;
		for (int i = 0; i < N; i++) {
			long a = stoi(st.nextToken());
			minHeap.add(a);
			sum += a;
		}
		
		for(int i=0; i<M; i++) {
			long temp = minHeap.remove()+minHeap.remove();
			minHeap.add(temp);
			minHeap.add(temp);
			sum += temp;
		}
		
		System.out.println(sum);
	}

}