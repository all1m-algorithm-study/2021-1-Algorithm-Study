package ALrim;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class boj10866 {

	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = null;
        Deque<Integer> deq = new ArrayDeque<>();
        
        for (int i=0;i<N;i++) {
        	st = new StringTokenizer(br.readLine()," ");
        	switch (st.nextToken()) {
        		case "push_front":
        			deq.addFirst(Integer.parseInt(st.nextToken()));
        			break;
        		case "push_back":
        			deq.addLast(Integer.parseInt(st.nextToken()));
        			break;
        		case "pop_front":
        			if (deq.isEmpty()) 
        				System.out.println(-1);
        			else 
        				System.out.println(deq.removeFirst());
        			break;
        		case "pop_back":
        			if (deq.isEmpty()) 
        				System.out.println(-1);
        			else 
        				System.out.println(deq.removeLast());
        			break;
        		case "size":
        			System.out.println(deq.size());
        			break;
        		case "empty":
        			if (deq.isEmpty())
        				System.out.println(1);
        			else
        				System.out.println(0);
        			break;
        		case "front":
        			if (deq.isEmpty())
        				System.out.println(-1);
        			else
        				System.out.println(deq.getFirst());
        			break;
        		case "back":
        			if (deq.isEmpty())
        				System.out.println(-1);
        			else
        				System.out.println(deq.getLast());
        			break;
        	}

        }
	}
}
