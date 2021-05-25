package alim;
import java.util.*;

public class boj2504_subln516 {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		Stack<Character> stack = new Stack<Character>();
		
		int mul = 1, result = 0;
		String in = scan.next();
		
		for (int i = 0; i < in.length(); i++) {
			switch (in.charAt(i)) { 
			case '(': 
				stack.push('(');
				mul *= 2;
				break;
			case '[':
				stack.push('[');
				mul *= 3;
				break;
			case ')':
				if (stack.isEmpty() || stack.peek() != '(') {
					result = 0;
					break;
				}
				
				if (in.charAt(i - 1) == '(') result += mul;
				stack.pop();
				mul /= 2;
				break;
			case ']':
				if (stack.isEmpty() || stack.peek() != '[') {
					result = 0;
					break;
				}
				
				if (in.charAt(i - 1) == '[') result += mul;
				stack.pop();
				mul /= 3;
				break;
			}
		}
		
		if(stack.empty()) System.out.println(result);
		else System.out.println(0);
	}
}