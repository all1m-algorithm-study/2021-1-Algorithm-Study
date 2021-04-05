
import java.io.*;
import java.util.*;

class Boj_2615 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	static int[][] board = new int[19][19];
	static final int BLK = 1, WHT = 2;
	static final int[][] next = { { 1, 0 }, { 0, 1 }, { 1, 1 }, { -1, -1 } };

	static class Point {
		int winner, row, col;
		int cnt = 0;

		Point(int w, int r, int c) {
			winner = w;
			row = r;
			col = c;
			cnt = 1;
		}
	}

	static boolean inRange(int x) {
		if (0 <= x && x < 19)
			return true;
		return false;
	}

	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	static Point findWinner() {
		Point p = null;
		for (int i = 0; i < 19; i++) {
			p = findLine(i, 0, 0, 1); // horizon
			if (p != null)
				return p;

			p = findLine(0, i, 1, 0); // vertical
			if (p != null)
				return p;

			p = findLine(i, 0, 1, 1); // diagonal \
			if (p != null)
				return p;
			p = findLine(0, i, 1, 1);
			if (p != null)
				return p;

			p = findLine(i, 0, -1, 1); // diagonal /
			if (p != null)
				return p;
			p = findLine(18, i, -1, 1);
			if (p != null)
				return p;
		}
		return null;
	}

	static Point findLine(int r, int c, int dr, int dc) {
		Point p = new Point(0, 0, 0);
		while (inRange(r) && inRange(c)) {
			if (board[r][c] != p.winner) {
				if (p.cnt == 5)
					return p;
				p = new Point(board[r][c], r, c);
			} else if (board[r][c] == 0) {
				p.winner = 0;
			} else {
				p.cnt++;
			}
			r += dr;
			c += dc;
		}
		if (p.cnt == 5)
			return p;
		return null;
	}

	public static void main(String[] args) throws IOException {

		for (int i = 0; i < 19; i++) {
			String line = br.readLine();
			for (int j = 0; j < 19; j++) {
				board[i][j] = line.charAt(j * 2) - '0';
			}
		}

		Point p = findWinner();
		if (p == null)
			System.out.println(0);
		else {
			System.out.println(p.winner);
			System.out.printf("%d %d", p.row + 1, p.col + 1);
		}
	}

}