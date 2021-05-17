import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	final static String ERR = "error\n";
	static int N, K;
	static ArrayList[] lens;

	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	static long goodFriends() {
		long cnt = 0;
		for (int l = 2; l <= 20; l++) {
			ArrayList<Integer> cand = lens[l];
			for (int n = 0; n < cand.size(); n++) {
				int i = cand.get(n), j = K + i;
				int idx = Collections.binarySearch(cand, j);
				if (idx > 0) {
					cnt += (idx - n);
				} else {
					idx = ~idx;
					cnt+=(idx-n-1);
				}
				
			}
		}
		return cnt;
	}

	public static void main(String[] args) throws IOException {
		sb.setLength(0);
		st = new StringTokenizer(br.readLine());
		N = stoi(st.nextToken());
		K = stoi(st.nextToken());
		lens = new ArrayList[21];
		for (int i = 2; i <= 20; i++)
			lens[i] = new ArrayList<Integer>();
		for (int i = 0; i < N; i++) {
			String name = br.readLine();
			lens[name.length()].add(i);
		}
		System.out.println(goodFriends());
	}
}
