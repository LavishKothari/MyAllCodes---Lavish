package FEB18;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class CHEFPTNT {
	private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer stz;

	public static void main(String[] args) throws NumberFormatException, IOException {
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			stz = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(stz.nextToken());
			int m = Integer.parseInt(stz.nextToken());
			int x = Integer.parseInt(stz.nextToken());
			int k = Integer.parseInt(stz.nextToken());
			String str = br.readLine();
			if (solve(n, m, x, k, str))
				System.out.println("yes");
			else
				System.out.println("no");
		}
	}

	private static boolean solve(int n, int m, int x, int k, String str) {
		if (m == 0 || x == 0)
			return false;
		int oddWorkers, evenWorkers;
		oddWorkers = getOddWorkers(str);
		evenWorkers = k - oddWorkers;

		// oddWorkers = Math.min(oddWorkers, x);
		// evenWorkers = Math.min(evenWorkers, x);
		int canDo = 0;
		for (int i = 1; i <= m; i++) {
			// System.out.println("i = "+i);
			if (i % 2 == 0 && evenWorkers > 0) {
				int current = Math.min(evenWorkers, x);
				// System.out.println("currnt = "+current);
				canDo += current;
				evenWorkers -= current;
			} else if (i % 2 == 1 && oddWorkers > 0) {
				int current = Math.min(oddWorkers, x);
				// System.out.println("currnt = "+current);
				canDo += current;
				oddWorkers -= current;
			}
			if (canDo >= n)
				break;
		}
		// System.out.println("can do = "+canDo);
		return canDo >= n;
	}

	private static int getOddWorkers(String str) {
		int result = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str.charAt(i) == 'O')
				result++;
		}
		return result;
	}

}
