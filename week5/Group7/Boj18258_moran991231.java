import java.io.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	public static int stoi(String s) {
		return Integer.parseInt(s);
	}
	
	static class Queue{
		private int front=0, back=0;
		final int MAX = 2_000_001;
		private int[] arr = new int[2_000_001];
		
		private int next(int idx) {
			return (idx+1)%MAX;
		}
		
		private int previous(int idx) {
			return (MAX+idx-1)%MAX;
		}
		
		
		public void push(int x) {
			arr[back]=x;
			back = next(back);
		}
		public int pop() {
			if(isEmpty()==1)
				return -1;
			int ret = arr[front];
			front = next(front);
			return ret;
		}
		public int getSize() {
			if(front<=back)
				return back-front;
			else return MAX+back-front;
		}
		public int isEmpty() {
			if(front==back)
				return 1;
			else return 0;
		}
		public int getFront() {
			if(isEmpty()==1)
				return -1;
			return arr[front];
		}
		public int getBack() {
			if(isEmpty()==1)
				return -1;
			return arr[previous(back)];
		}
	}
	
	public static void main(String[] args) throws IOException{
		StringBuilder sb = new StringBuilder();
		Queue q = new Queue();
		int N = stoi(br.readLine());
		for(int i=0; i<N;i++) {
			String[] cmd = br.readLine().split(" ");
			if(cmd.length==2) {
				q.push(stoi(cmd[1]));
				continue;
			}
			char ch = cmd[0].charAt(0);
			if(ch=='p')
				sb.append(q.pop());
			else if (ch=='s')
				sb.append(q.getSize());
			else if (ch=='e')
				sb.append(q.isEmpty());
			else if(ch=='f')
				sb.append(q.getFront());
			else 
				sb.append(q.getBack());
			sb.append('\n');
		}
		System.out.println(sb.toString());
		
	}
	
}
