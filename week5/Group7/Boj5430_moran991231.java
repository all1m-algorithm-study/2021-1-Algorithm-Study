import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	final static String ERR = "error\n";

	
	static int stoi(String s) {
		return Integer.parseInt(s);
	}
	
	static int AC(char[] cmd, Deque<Integer>dq) {
		boolean direction=true;
		for(char ch:cmd) {
			if(ch == 'R')
				direction = !direction;
			else {
				if(dq.isEmpty())
					return -1;
				if(direction)
					dq.removeFirst();
				else
					dq.removeLast();
			}
		}
		return direction? 0:1;
		
	}
	
	static void print(Deque<Integer>dq, int ACretVal) {
		if(ACretVal<0) {
			sb.append(ERR);
			return;
		}
		sb.append('[');
		while(dq.size()>1) {
			int x;
			if(ACretVal==0)
				x=dq.removeFirst()	;
			else
				x=dq.removeLast();
			
			sb.append(x).append(',');
		}
		if(!dq.isEmpty())
			sb.append(dq.remove());
		sb.append(']').append('\n');
	}

	public static void main(String[] args) throws IOException {
		sb.setLength(0);
		int T = stoi(br.readLine());
		
		for(int t=0; t<T;t++) {
			Deque <Integer>dq = new LinkedList<>();
			
			char[] cmd = br.readLine().toCharArray();
			int N = stoi(br.readLine());
			
			String sArr = br.readLine();
			sArr = sArr.substring(1,sArr.length()-1);
			if(sArr.length()>0) {
				st = new StringTokenizer(sArr, ",");
				for(int i=0; i<N;i++)
					dq.add(stoi(st.nextToken()));

			}
			int ACretVal = AC(cmd,dq);
			print(dq,ACretVal);
		}
		System.out.println(sb.toString());
	}
}
