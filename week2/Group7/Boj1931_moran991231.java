

import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int stoi(String s) {
		return Integer.parseInt(s);
	}
	
	static class Meeting implements Comparable<Meeting>{
		int start, end;
		Meeting(int s, int e){
			start =s;
			end =e;
		}
		
		public int compareTo(Meeting m) {
			if(this.end == m.end)
				return this.start-m.start;
			return this.end - m.end;
		}
		
	}
	
	static int countUsableMeetings(Meeting[] meets, int N) {
		int cnt=0;
		int end=0;
		for(Meeting m: meets) {
			if(end<=m.start) {
				cnt++;
				end = m.end;
			}
		}
		
		return cnt;
	}

	public static void main(String[] args) throws IOException{
		int N = stoi(br.readLine());
		Meeting[] meets = new Meeting[N];
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			meets[i] = new Meeting(stoi(st.nextToken()), stoi(st.nextToken()));
		}
		Arrays.sort(meets);
		
		System.out.println(countUsableMeetings(meets, N));
	}

}