
import java.io.*;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	static int N, M;
	static char[][] map;
	static ArrayList<Cross> cList;

	static class Cross {
		int x, y, size;

		Cross(int x, int y, int size) {
			this.x = x;
			this.y = y;
			this.size = size;
		}
	}

	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	static void makeCrossList() {
		cList = new ArrayList<>();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == '.')
					continue;
				addCrossToList(i, j, cList);
			}
		}
	}

	static void addCrossToList(int x, int y, ArrayList<Cross> cList) {
		int temp1 = Math.min(x, y);
		int temp2 = Math.min(N - 1 - x, M - 1 - y);
		int max = Math.min(temp1, temp2); // prevent index errors

		for (int size = 0; size <= max; size++) {
			if (map[x + size][y] == '#' && map[x - size][y] == '#' && map[x][y + size] == '#'
					&& map[x][y - size] == '#') {
				cList.add(new Cross(x, y, size));
			} else
				break;
		}
	}

	static int bruteForce() {
		int max = 1;
		int area1 = 0, area2 = 0;
		int numCross = cList.size();

		for (int i = 0; i < numCross; i++) {
			area1 = cList.get(i).size * 4 + 1;
			putCross(cList.get(i), '*');

			for (int j = i + 1; j < numCross; j++) {
				if (isAbleToPutCross(cList.get(j))) {
					area2 = cList.get(j).size * 4 + 1;
					max = Math.max(max, area1 * area2);
				}
			}
			putCross(cList.get(i), '#');
		}

		return max;
	}

	static void putCross(Cross c, char fill) {
		int x = c.x, y = c.y, size = c.size;
		for (int s = 0; s <= size; s++) {
			map[x + s][y] = fill;
			map[x - s][y] = fill;
			map[x][y + s] = fill;
			map[x][y - s] = fill;
		}
	}

	static boolean isAbleToPutCross(Cross c) {
		int x = c.x, y = c.y, size = c.size;
		for (int s = 0; s <= size; s++) {
			if (!(map[x + s][y] == '#' && map[x - s][y] == '#' && map[x][y + s] == '#' && map[x][y - s] == '#'))
				return false;
		}
		return true;
	}

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		N = stoi(st.nextToken());
		M = stoi(st.nextToken());
		map = new char[N][];
		for (int i = 0; i < N; i++)
			map[i] = br.readLine().toCharArray();

		makeCrossList();
		int max = bruteForce();

		System.out.println(max);

	}

}