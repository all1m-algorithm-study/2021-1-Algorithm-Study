

import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st_road,st_price;
	
	static long stol(String s) {
		return Long.parseLong(s);
	}

	public static void main(String[] args) throws IOException{
		int N = Integer.parseInt(br.readLine());
		st_road = new StringTokenizer(br.readLine());
		st_price = new StringTokenizer(br.readLine());
		
		long price = Integer.MAX_VALUE;
		long total_cost = 0L;
		for(int i=0; i<N-1; i++) {
			price = Math.min(price, stol(st_price.nextToken()));
			total_cost += price * stol(st_road.nextToken());
		}
		System.out.println(total_cost);
	}

}