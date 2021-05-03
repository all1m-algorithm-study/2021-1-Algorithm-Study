package alim;
import java.io.*;
import java.util.*;

public class boj4779_subln516 {
	public static char[] list = new char[59050];
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader BR  =new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter BW = new BufferedWriter(new OutputStreamWriter(System.out));
		String input = "";
		
		while((input=BR.readLine())!=null) {
			int N = Integer.parseInt(input);
			int range = (int)Math.pow(3, N);
			for (int i=0; i<range; i++)
				list[i]=' ';
			Cantor(0,range-1,range);
			for (int i=0; i<range; i++)
				BW.write(list[i]);
			BW.newLine();
			BW.flush();
		}
		BW.close();
		
	}
	public static void Cantor(int first, int last, int range) {
		if (range==1) {
			list[first]='-';
		}
		else {
			range = range/3;
			Cantor(first,first+(range-1),range);
			Cantor(last+1-range, last, range);
		}
	}

}
