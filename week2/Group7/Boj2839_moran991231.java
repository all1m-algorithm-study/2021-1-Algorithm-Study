

import java.io.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	
	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	public static void main(String[] args) throws IOException{
		int N = stoi(br.readLine());
		
		int cnt=0;
		while(N%5 !=0 && N>0) {
			cnt++;
			N -=3;
		}
		if(N <0) cnt =-1;
		else
			cnt += N/5;
		System.out.println(cnt);
	}

}