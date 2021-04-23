
import java.io.*;
import java.util.*;

class Boj_2503 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	static class QnA {
		char[] num;
		int strike, ball;

		QnA(char[] num, int strike, int ball) {
			this.num = num;
			this.strike = strike;
			this.ball = ball;
		}

		boolean test(char[] n) {
			int s = 0, b = 0;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (num[i] == n[j]) {
						if (i == j)
							s++;
						else
							b++;
					}
				}
			}
			if (strike == s && ball == b)
				return true;
			return false;
		}
	}

	static int stoi(String s) {
		return Integer.parseInt(s);
	}
	
	static int cntNum(QnA[] qna) {
		int cnt=0;
		char[] n = new char[3];
		
		for(char a ='1'; a<='9'; a++) {
			n[0]=a;
			for(char b = '1'; b<='9'; b++) {
				if(a==b) continue;
				n[1]=b;
				for(char c='1'; c<='9'; c++) {
					if(a==c || b==c) continue;
					n[2]=c;
					
					// test
					boolean isAvailable=true;
					for(QnA ans: qna) {
						if(ans.test(n)==false) {
							isAvailable=false;
							break;
						}
					}
					if(isAvailable) cnt++;
				}
			}
		}
		
		return cnt;
	}

	public static void main(String[] args) throws IOException {

		int N = stoi(br.readLine());
		QnA[] qna = new QnA[N];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			qna[i] = new QnA(st.nextToken().toCharArray(), stoi(st.nextToken()), stoi(st.nextToken()));
		}
		
		System.out.println(cntNum(qna));
	}

}