package CCU2018;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class C3PRB2 {
	private final static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer stz;

	public static void main(String[] args) throws NumberFormatException, IOException {
		stz = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(stz.nextToken());
		List<Long> x, y;
		x = new ArrayList<>();
		y = new ArrayList<>();
		while (n-- > 0) {
			stz = new StringTokenizer(br.readLine());
			x.add(Long.parseLong(stz.nextToken()));
			y.add(Long.parseLong(stz.nextToken()));
		}
		solve(x, y);
	}

	private static void solve(List<Long> x, List<Long> y) {
		long count = 0;
		for (int i = 0; i < x.size(); i++) {
			for (int j = i + 1; j < y.size(); j++) {
				long a = calEuclid2(x, y, i, j);
				long b = calMahnatten2(x, y, i, j);
				if (a == b)
					count++;
			}
		}
		System.out.println(count);
	}

	private static long calEuclid2(List<Long> x, List<Long> y, int i, int j) {
		return (x.get(i) - x.get(j)) * (x.get(i) - x.get(j)) + (y.get(i) - y.get(j)) * (y.get(i) - y.get(j));
	}

	private static long calMahnatten2(List<Long> x, List<Long> y, int i, int j) {
		long dist = Math.abs(x.get(i) - x.get(j)) + Math.abs(y.get(i) - y.get(j));
		return dist * dist;
	}

}
