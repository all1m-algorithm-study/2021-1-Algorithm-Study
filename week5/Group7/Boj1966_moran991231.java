import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	
	static int stoi(String s) {
		return Integer.parseInt(s);
	}
	static class Document{
		int num, importance;
		Document(int n, int i){
			num=n;
			importance=i;
		}
	}
	
	static Queue<Document> q = new LinkedList<>();
	static PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());

	
	public static int print(int target) {
		int cnt=0;
		while(true) {
			Document doc = q.peek();
			if(doc.importance != maxHeap.peek())
				q.add(q.remove());
			else {
				q.remove();
				maxHeap.remove();
				cnt++;
				if(doc.num == target)
					break;
			}
		}
		
		return cnt;
	}
	public static void main(String[] args) throws IOException {
		sb.setLength(0);
		int T = stoi(br.readLine());
		int N, nDoc;
		
		for(int t=0; t<T;t++) {
			q.clear();
			maxHeap.clear();
			
			st = new StringTokenizer(br.readLine());
			N = stoi(st.nextToken());
			nDoc = stoi(st.nextToken());
			
			st = new StringTokenizer(br.readLine());
			for(int i=0; i<N;i++) {
				int importance = stoi(st.nextToken());
				q.add(new Document(i,importance));
				maxHeap.add(importance);
			}
			
			sb.append(print(nDoc)).append('\n');
		}

		System.out.println(sb.toString());
	}
}
