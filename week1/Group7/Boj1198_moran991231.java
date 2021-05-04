
import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	static int N;
	static Point[] points;

	static class Point {
		int x, y;

		Point(int a, int b) {
			x = a;
			y = b;
		}
	}

	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	public static void main(String[] args) throws IOException {
		N = stoi(br.readLine());
		points = new Point[N];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			points[i] = new Point(stoi(st.nextToken()), stoi(st.nextToken()));
		}

		double area=0.0;
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				for (int k = j + 1; k < N; k++) {
					Point p1 = points[i], p2 = points[j], p3 = points[k];
					int a1 = p2.x - p1.x, a2 = p2.y - p1.y;
					int b1 = p3.x - p1.x, b2 = p3.y - p1.y;
					double tempArea = Math.abs((a1 * b2 - a2 * b1)/2.0);
					area = Math.max(area, tempArea);
				}
			}
		}

//		if(area%2==0) System.out.println(area/2+".0");
//		else System.out.println(area/2+".5");
		System.out.printf("%.1f", area);
	}

}