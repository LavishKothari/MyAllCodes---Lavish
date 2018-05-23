package FEB18;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class BROCLK {
	private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer stz;

	public static void main(String[] args) throws NumberFormatException, IOException {
		int T = Integer.parseInt(br.readLine());
		while (T-- > 0) {
			stz = new StringTokenizer(br.readLine());
			long l, d, t;
			l = Long.parseLong(stz.nextToken());
			d = Long.parseLong(stz.nextToken());
			t = Long.parseLong(stz.nextToken());
			solve(l, d, t);
		}
	}

	private static void solve(long l, long d, long t) {
		long answer = 1;
		if (t == 1) {
			answer = d * NumberUtils.modularInverse(l, NumberUtils.MOD);
		}
		if (t == 2) {
			answer *= NumberUtils.modularInverse(l * l, NumberUtils.MOD);
			answer *= (2 * d * d - l * l) % NumberUtils.MOD;
		}
		if (t == 3) {
			long temp = (4 * d * d - 3 * l * l) % NumberUtils.MOD * d;
			answer *= (temp % NumberUtils.MOD);
			answer *= NumberUtils.modularInverse((l * l)%NumberUtils.MOD * l, NumberUtils.MOD);
		}
		answer %= NumberUtils.MOD;
		answer = (answer*l)%NumberUtils.MOD;
		answer += NumberUtils.MOD;
		answer %= NumberUtils.MOD;
		System.out.println(answer);
	}
}

final class NumberUtils {
	public static int MOD = 1000000007;

	private NumberUtils() {

	}

	public static long modularInverse(long a, long b) {
		return NumberUtils.power(a, b - 2, b);
	}

	public static long power(long a, long b, long m) {
		if (b == 0)
			return 1;
		if (b == 1)
			return a;
		long temp = NumberUtils.power(a, b / 2, m);
		if (b % 2 == 0)
			return (temp * temp) % m;
		return (((temp * temp) % m) * a) % m;
	}

}