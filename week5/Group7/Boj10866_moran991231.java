import java.io.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	public static int stoi(String s) {
		return Integer.parseInt(s);
	}

	static class Deque {
		private int front = 0, back = 0;
		final int MAX = 10_001;
		private int[] arr = new int[MAX];

		private int next(int idx) {
			return (idx + 1) % MAX;
		}

		private int previous(int idx) {
			return (MAX + idx - 1) % MAX;
		}

		public void push_front(int x) {
			front = previous(front);
			arr[front] = x;
		}

		public void push_back(int x) {
			arr[back] = x;
			back = next(back);
		}

		public int pop_front() {
			if (isEmpty() == 1)
				return -1;
			int ret = arr[front];
			front = next(front);
			return ret;
		}

		public int pop_back() {
			if (isEmpty() == 1)
				return -1;
			back = previous(back);
			int ret = arr[back];
			return ret;
		}

		public int getSize() {
			if (front <= back)
				return back - front;
			else
				return MAX + back - front;
		}

		public int isEmpty() {
			if (front == back)
				return 1;
			else
				return 0;
		}

		public int getFront() {
			if (isEmpty() == 1)
				return -1;
			return arr[front];
		}

		public int getBack() {
			if (isEmpty() == 1)
				return -1;
			return arr[previous(back)];
		}
	}

	public static void main(String[] args) throws IOException {
		StringBuilder sb = new StringBuilder();
		Deque dq = new Deque();
		int N = stoi(br.readLine());
		for (int i = 0; i < N; i++) {
			String[] cmd = br.readLine().split(" ");
			if (cmd.length == 2) {
				if (cmd[0].charAt(5) == 'f')
					dq.push_front(stoi(cmd[1]));
				else
					dq.push_back(stoi(cmd[1]));
				continue;
			}
			char ch = cmd[0].charAt(0);
			if (ch == 'p') {
				if (cmd[0].charAt(4) == 'f')
					sb.append(dq.pop_front());
				else
					sb.append(dq.pop_back());

			} else if (ch == 's')
				sb.append(dq.getSize());
			else if (ch == 'e')
				sb.append(dq.isEmpty());
			else if (ch == 'f')
				sb.append(dq.getFront());
			else
				sb.append(dq.getBack());
			sb.append('\n');
		}
		System.out.println(sb.toString());

	}

}
