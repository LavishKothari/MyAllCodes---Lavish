import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class GIT01 {

	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	public static void main(String[] args) throws IOException {
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			StringTokenizer stz = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(stz.nextToken());
			int m = Integer.parseInt(stz.nextToken());
			char[][] matrix = new char[n][m];

			for (int i = 0; i < n; i++) {
				String currentString = br.readLine();
				for (int j = 0; j < m; j++) {
					matrix[i][j] = currentString.charAt(j);
				}
			}
			System.out.println(solve(matrix));
		}
	}

	private static int solve(char[][] matrix) {
		int x = calCost(matrix, 'R');
		int y = calCost(matrix, 'G');
		return x < y ? x : y;
	}

	private static char getOtherChar(char c) {
		if (c == 'G')
			return 'R';
		else
			return 'G';
	}

	private static char getCharacter(char start, int i, int j) {
		if ((i + j) % 2 == 0)
			return start;
		else
			return getOtherChar(start);
	}

	private static int calCost(char[][] matrix, char start) {
		int cost = 0;
		for (int i = 0; i < matrix.length; i++) {
			for (int j = 0; j < matrix[i].length; j++) {
				if (getCharacter(start, i, j) != matrix[i][j]) {
					if (matrix[i][j] == 'R')
						cost += 5;
					else
						cost += 3;
				}
			}
		}
		return cost;
	}
}
