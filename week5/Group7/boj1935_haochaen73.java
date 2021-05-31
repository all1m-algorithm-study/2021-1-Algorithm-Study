package ALrim;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class boj1935 {

    public static void main(String[] args) throws IOException {
        BufferedReader Br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(Br.readLine());
        String input = Br.readLine();

        int[] arr = new int[N];
        for(int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(Br.readLine());
        }

        Stack<Double> oper = new Stack<>();
        int len = input.length();
        for(int i = 0; i < len; i++) {
            char ch = input.charAt(i);
            if('A' <= ch && ch <= 'Z') {  
                double d = arr[ch - 'A'];
                oper.push(d);
            }else {  
                double d1 = oper.pop();
                double d2 = oper.pop();
                double d3 = 0;
                switch(ch) {
                    case '+' :
                        d3 = d2 + d1;
                        break;
                    case '-' :
                        d3 = d2 - d1;
                        break;
                    case '*' :
                        d3 = d2 * d1;
                        break;
                    case '/' :
                        d3 = d2 / d1;
                        break;
                }
                oper.push(d3);
            }
        }
        System.out.printf("%.2f", oper.pop());
    }
}
