import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int length,width,height,N;
	static long[] cubes;
	static int[] pow = new int[20];
	static int num=0;
	
	static int stoi(String s) {
		return Integer.parseInt(s);
	}
	
	static void makeCubeLen() {
		pow[0]=1;
		for(int i=1; i<20; i++)
			pow[i]=pow[i-1]*2;
	}
	
	
	static boolean fillBox(int l, int w, int h) { // l <= w <= h
		int temp;// l <= w <= h
		if(l>w) {
			temp=l;
			l=w;
			w=temp;
		}
		if(w>h) {
			temp=w;
			w=h;
			h=temp;
		}
		if(l>w) {
			temp=l;
			l=w;
			w=temp;
		}
		if(l==0) return true;
		if(l==1) {
			cubes[0] -= (long)w*h;
			num += (long)w*h;
			return (cubes[0]>=0)? true:false;
		}
		
		for(int i=19; 0<=i; i--) {
			if(cubes[i]==0)continue;
			if(l<pow[i]) continue;
			int x = pow[i];
			cubes[i]--;
			num++;
			if(!fillBox(l-x,w,h)) return false;
			if(!fillBox(x,x,h-x))return false;
			if(!fillBox(x,w-x,h	))return false;
			return true;
		}
		
		
		return false;		
	}

	public static void main(String[] args) throws IOException{
		if(pow[0]==0)
			makeCubeLen();
		num=0;
		st = new StringTokenizer(br.readLine());
		length = stoi(st.nextToken());
		width = stoi(st.nextToken());
		height = stoi(st.nextToken());
		N = stoi(br.readLine());
		cubes = new long[20];
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			cubes[stoi(st.nextToken())] = stoi(st.nextToken());
		}
		
		if(!fillBox(length,width,height))
			num=-1;
		System.out.println(num);
	}

}