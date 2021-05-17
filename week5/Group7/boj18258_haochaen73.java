package ALrim;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.LinkedList;

public class boj18258 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = null;
        Queue<Integer> que = new LinkedList<>();
        int last = 0, x=0;
        
        for (int i=0;i<N;i++) {
        	st = new StringTokenizer(br.readLine());
        	switch (st.nextToken()) {
        		case "push":
        			x = Integer.parseInt(st.nextToken());
        			last = x;
        			que.add(x);
        			break;
        		case "pop":
        			if (que.isEmpty()) 
        				System.out.println(-1);
        			else 
        				System.out.println(que.poll());
        			break;
        		case "size":
        			System.out.println(que.size());
        			break;
        		case "empty":
        			if (que.isEmpty())
        				System.out.println(1);
        			else
        				System.out.println(0);
        			break;
        		case "front":
        			if (que.isEmpty())
        				System.out.println(-1);
        			else
        				System.out.println(que.peek());
        			break;
        		case "back":
        			if (que.isEmpty())
        				System.out.println(-1);
        			else
        				System.out.println(last);
        			break;
        	
        	}
        }
    }
}
