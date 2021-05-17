import java.io.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();

	static void deciToBin(long n) {
		if (n == 0L)
			return;
		long remainder = n & 1L;
		n /= 2L;

		deciToBin(n);
		sb.append(remainder);
	}

	public static void main(String[] args) throws IOException {
		sb.setLength(0);
		long N = Long.parseLong(br.readLine());

//		deciToBin(N);
//		System.out.println(sb.toString());
		System.out.println(Long.toBinaryString(N));
	}

}