import java.io.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	public static class Stack {
		private int size = 0;
		private int[] arr = new int[10000];

		public void push(int x) {
			arr[size++] = x;
		}

		public int pop() {
			if (size > 0)
				return arr[--size];
			return -1;
		}

		public int getSize() {
			return size;
		}

		public int isEmpty() {
			if (size > 0)
				return 0;
			else
				return 1;
		}

		public int getTop() {
			if (size > 0)
				return arr[size - 1];
			return -1;
		}
	}
	
	public static int stoi(String s) {
		return Integer.parseInt(s);
	}
	
	public static void main(String[] args) throws IOException{
		StringBuilder sb = new StringBuilder();
		Stack stk = new Stack();
		int N = stoi(br.readLine());
		for(int i=0; i<N;i++) {
			String[] cmd = br.readLine().split(" ");
			if(cmd.length==2) {
				stk.push(stoi(cmd[1]));
				continue;
			}
			char ch = cmd[0].charAt(0);
			if(ch=='p')
				sb.append(stk.pop());
			else if (ch=='s')
				sb.append(stk.getSize());
			else if (ch=='e')
				sb.append(stk.isEmpty());
			else
				sb.append(stk.getTop());
			sb.append('\n');
		}
		System.out.println(sb.toString());
		
	}
	
}
