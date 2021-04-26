

import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int N, K, R, C;
	static int order = 0;

	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	public static void orderZ(int r, int c, int k) {
		if (k == 1)
			return;
		k /= 2;
		int kk = k * k;
		if (r >= k) {
			order += 2 * kk;
			r -= k;
		}
		if(c>=k) {
			order += kk;
			c-=k;
		}
		
		orderZ(r,c,k);
		return;
	}
	
	public static void orderZ_2(int r, int c, int k) {
		int kk=0;
		while(k!=1) {
			k/=2;
			kk=k*k;
			if (r >= k) {
				order += 2 * kk;
				r -= k;
			}
			if(c>=k) {
				order += kk;
				c-=k;
			}
		}
	}

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		N = stoi(st.nextToken());
		R = stoi(st.nextToken());
		C = stoi(st.nextToken());
		K = 1;
		for (int i = 0; i < N; i++)
			K *= 2;
		order = 0;
//		orderZ(R,C,K);
		orderZ_2(R,C,K);
		System.out.println(order);
	}

}