package APRIL18;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.TreeMap;

class WGHTNUM {
	private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer stz;

	private static Map<Integer, Integer> map;

	public static void main(String[] args) throws NumberFormatException, IOException {
		populate();
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			stz = new StringTokenizer(br.readLine());
			long n = Long.parseLong(stz.nextToken());
			int w = Integer.parseInt(stz.nextToken());
			long answer = solve(n, w);
			System.out.println(answer);
		}
	}

	private static long solve(long n, int w) {
		if (!map.containsKey(w))
			return 0;
		if (n == 2) 
			return map.get(w);
		return (power(10, n - 2, 1000000007L) * map.get(w)) % 1000000007L;
	}

	private static long power(long a, long b, long mod) {
		if (a == 0)
			return 0;
		if (b == 0)
			return 1;
		if (b == 1)
			return a;
		long temp = power(a, b / 2, mod);
		long x = (temp * temp) % mod;
		if (b % 2 == 0)
			return x;
		else
			return (x * a) % mod;
	}

	private static void populate() {
		map = new TreeMap<>();
		for (int i = 0; i < 10; i++) {
			for (int j = 1; j < 10; j++) {
				if (map.containsKey(i - j)) {
					int prev = map.get(i - j);
					map.remove(i - j);
					map.put(i - j, prev + 1);
				} else
					map.put(i - j, 1);
			}
		}
	}
}
