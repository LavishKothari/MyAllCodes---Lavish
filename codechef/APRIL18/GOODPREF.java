package APRIL18;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

class GOODPREF {
	private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer stz;

	public static void main(String[] args) throws NumberFormatException, IOException {
		long t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			stz = new StringTokenizer(br.readLine());
			String s = stz.nextToken();
			long n = Integer.parseInt(stz.nextToken());
			System.out.println(solve(s, n));
		}
	}

	private static long solve(String s, long n) {
		List<Long> list = new ArrayList<>(s.length());
		List<Long> sum = new ArrayList<>(s.length());
		Map<Long, Long> map = new HashMap<>();

		for (int i = 0; i < s.length(); i++) {
			char c = s.charAt(i);
			if (c == 'a')
				list.add(1L);
			else
				list.add(-1L);
			long x = i == 0 ? 0 : sum.get(i - 1);
			sum.add(x + list.get(i));
			if (map.containsKey(sum.get(i))) {
				long previousCount = map.get(sum.get(i));
				map.remove(sum.get(i));
				map.put(sum.get(i), previousCount + 1);
			} else {
				map.put(sum.get(i), 1L);
			}
		}

		long count = 0;

		long totalSum = sum.get(sum.size() - 1);
		if (totalSum == 0) {
			for (int i = 0; i < sum.size(); i++)
				if (sum.get(i) > 0)
					count++;
			return count*n;
		}

		for (long i = 0; i < n; i++) {
			long currentPrefixSum = totalSum * i;
			if (currentPrefixSum < -1000)
				break;
			if (currentPrefixSum > 1000) {
				count += s.length()*(n-i);
				break;
			}
			for (long j = -currentPrefixSum + 1; j <= 1000; j++) {
				if (map.containsKey(j)) {
					count += map.get(j);
				}
			}
		}

		return count;
	}

}
