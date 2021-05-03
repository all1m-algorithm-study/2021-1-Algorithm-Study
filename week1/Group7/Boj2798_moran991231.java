
import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	public static void main(String[] args) throws IOException{

		st= new StringTokenizer(br.readLine());
		int N,M,sum=0;
		N = stoi(st.nextToken());
		M = stoi(st.nextToken());
		
		int[] cards = new int[N];
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; i++)
			cards[i] = stoi(st.nextToken());
		
		int a,b,c;
		for(int i=0; i<N; i++) {
			a=cards[i];
			for(int j=i+1; j<N; j++) {
				b=a+cards[j];
				for(int k=j+1; k<N; k++	) {
					c = b+cards[k];
					if(sum<c && c<=M) sum=c;
				}
			}
		}
		System.out.println(sum);
	}

}