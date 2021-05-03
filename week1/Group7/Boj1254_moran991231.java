
import java.io.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	static int stoi(String s) {
		return Integer.parseInt(s);
	}
	static boolean isPalindrom(char[] str, int len, int x) {
		for(int i=x; i<(len+x)/2; i++)
			if(str[i] != str[len+x-1-i]) return false;
		return true;
	}

	public static void main(String[] args) throws IOException{
		char[] str = br.readLine().toCharArray();
		
		int strLen = str.length;
		for(int x=0; x<=strLen; x++	) {
			if(isPalindrom(str, strLen,x)) {
				System.out.println(strLen+x);
				break;
			}
				
		}
		
	}

}