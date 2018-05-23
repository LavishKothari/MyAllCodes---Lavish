package MARCH18B;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.StringTokenizer;

public class MIXCOLOR {
	private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer stz;

	public static void main(String[] args) throws NumberFormatException, IOException {
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			int n = Integer.parseInt(br.readLine());
			stz = new StringTokenizer(br.readLine());
			List<Integer> values = new ArrayList<>(n);
			for (int i = 0; i < n; i++) {
				values.add(Integer.parseInt(stz.nextToken()));
			}
			solve(values);
		}
	}

	private static void solve(List<Integer> values) {
		Map<Integer, Integer> m = new HashMap<>();
		for (final Integer currentValue : values) {
			if (m.containsKey(currentValue)) {
				Integer count = m.get(currentValue);
				m.remove(currentValue);
				m.put(currentValue, count + 1);
			} else
				m.put(currentValue, 1);
		}
		long answer=0;
		for(final Entry<Integer,Integer> entry : m.entrySet()) {
			answer += (entry.getValue()-1);
		}
		System.out.println(answer);
	}

}
