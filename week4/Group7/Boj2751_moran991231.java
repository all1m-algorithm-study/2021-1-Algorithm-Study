import java.io.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static int N;
	static int[] arr,ret;
	
	static int stoi(String s) {
		return Integer.parseInt(s);
	}
	static void mergeSort(int s1,  int s2, int e2) {
		if(s1 == s2) {
			return;
		}
			
		
		mergeSort(s1,(s1+s2)/2,s2);
		mergeSort(s2,(s2+e2)/2,e2);
		
		int i1=s1, i2=s2, iret=s1;
		while(i1<s2 && i2<e2) {
			if(arr[i1]<=arr[i2]) {
				ret[iret++] = arr[i1++];
			}else {
				ret[iret++] = arr[i2++];
			}
			
		}
		if(i2<e2) {
			i1=i2;
		}
		for(;iret<e2; iret++)
			ret[iret]= arr[i1++];
		for(int i=s1; i<e2; i++)
			arr[i]=ret[i];
		
	}

	public static void main(String[] args) throws IOException{
		sb.setLength(0);
		N = stoi(br.readLine());
		arr = new int[N];
		ret = new int[N];
		for(int i=0; i<N; i++)
			arr[i] = stoi(br.readLine());
		mergeSort(0,N/2,N);
		for(int x:arr)
			sb.append(x).append('\n');
		System.out.println(sb.toString());
	}

}

