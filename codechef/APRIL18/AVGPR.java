package APRIL18;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class AVGPR {
	private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer stz;

	public static void main(String[] args) throws NumberFormatException, IOException {
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			int n = Integer.parseInt(br.readLine());

			Map<Integer, Long> map = new HashMap<>();
			stz = new StringTokenizer(br.readLine());
			for (int i = 0; i < n; i++) {
				int x = (Integer.parseInt(stz.nextToken()));
				if (map.containsKey(x)) {
					long previousCount = map.get(x);
					map.remove(x);
					map.put(x, previousCount + 1);
				} else
					map.put(x, 1L);
			}
			long count1 = 0, count2 = 0;
			for (int i = -1000; i <= 1000; i++) {
				for (int j = -1000; j <= 1000; j++) {
					if ((i + j) % 2 != 0)
						continue;
					int x = (i + j) / 2;
					if (i != j && map.containsKey(i) && map.containsKey(j) && map.containsKey(x)) {
						count1 += map.get(i) * map.get(j);
					} else if (i == j && map.containsKey(i) && map.get(i) > 1) {
						long y = map.get(i);
						count2 += (y * (y - 1)) / 2;
					}
				}
			}
			System.out.println(count1/2 + count2);
		}
	}

}
