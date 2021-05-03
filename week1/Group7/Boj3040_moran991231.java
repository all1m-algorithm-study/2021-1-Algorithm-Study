
import java.io.*;

class Main {
	
	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int[] dwarves = new int[9];
		int sum=0;
		for(int i=0; i<9; i++) {
			dwarves[i]=stoi(br.readLine());
			sum += dwarves[i];
		}
		
		for(int i=0; i<9; i++) {
			for(int j=i+1; j<9; j++) {
				if(sum-dwarves[i]-dwarves[j] == 100) {
					dwarves[i]=dwarves[j]=-1;
					i=9;
					break;
				}
			}
		}
		
		for(int d: dwarves) 
			if(d>0) sb.append(d).append('\n');
		
		System.out.println(sb.toString());
	}

}
