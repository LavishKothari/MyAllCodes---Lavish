package FEB18.cos;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BROCLK {
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
		FractionWithPower costtheta = NumberUtils.cosntheta(t, new FractionWithPower(d, l));
		FractionWithPower newd = FractionWithPower.multiply(costtheta, new FractionWithPower(l));
		// newd.reduce();
		long x = newd.getFraction().getNumerator();
		long y = newd.getFraction().getDenominator();
		long answer = (x * NumberUtils.modularInverse(y, 1000000007)) % 1000000007;
		answer = (answer + 1000000007) % 1000000007;
		System.out.println(answer);
	}
}




