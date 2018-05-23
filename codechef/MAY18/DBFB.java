package MAY18;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class DBFB {

	private static List<Long> fib;
	private static final int MAX = 100010;
	private static final long MOD = 1000000007L;

	public static void main(String[] args) throws NumberFormatException, IOException {
		populateFib();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			StringTokenizer stz = new StringTokenizer(br.readLine());

			int m = Integer.parseInt(stz.nextToken());
			int n = Integer.parseInt(stz.nextToken());

			long sum1 = 0, sum2 = 0;
			stz = new StringTokenizer(br.readLine());
			for (int i = 0; i < m; i++) {
				sum1 = (sum1 + Integer.parseInt(stz.nextToken())) % MOD;
			}
			stz = new StringTokenizer(br.readLine());
			for (int i = 0; i < m; i++) {
				sum2 = (sum2 + Integer.parseInt(stz.nextToken())) % MOD;
			}

			if (n == 1) {
				System.out.println((sum1 * m) % MOD);
			} else if (n == 2) {
				System.out.println((sum2 * m) % MOD);
			} else {
				long answer1 = 0, answer2 = 0;
				if (n - 2 >= 0)
					answer1 = ((fib.get(n - 2) * sum1) % MOD * m) % MOD;
				if (n - 1 >= 0)
					answer2 = ((fib.get(n - 1) * sum2) % MOD * m) % MOD;
				System.out.println((answer1 + answer2) % MOD);
			}
		}
	}

	private static void populateFib() {
		fib = new ArrayList<>(MAX);
		fib.add(0L);
		fib.add(1L);
		for (int i = 2; i < MAX; i++) {
			fib.add((fib.get(i - 1) + fib.get(i - 2)) % MOD);
		}
	}

}
