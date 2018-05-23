package MAY18;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.stream.Collectors;

public class FAKEBS {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			StringTokenizer stz = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(stz.nextToken());
			int q = Integer.parseInt(stz.nextToken());

			stz = new StringTokenizer(br.readLine());
			List<Integer> list = new ArrayList<>(n);

			for (int i = 0; i < n; i++) {
				list.add(Integer.parseInt(stz.nextToken()));
			}
			List<Integer> sortedList = list.stream().sorted().collect(Collectors.toList());
			Map<Integer, Integer> bigger = new HashMap<>(n);
			Map<Integer, Integer> smaller = new HashMap<>(n);
			Map<Integer, Integer> index = new HashMap<>(n);

			for (int i = 0; i < sortedList.size(); i++) {
				bigger.put(sortedList.get(i), n - i - 1);
				smaller.put(sortedList.get(i), i - 1 + 1);
				index.put(list.get(i), i);
			}

			for (int i = 0; i < q; i++) {
				int x = Integer.parseInt(br.readLine());
				sovle(x, bigger, smaller, index, list);
			}
		}
	}

	private static void sovle(int x, Map<Integer, Integer> bigger, Map<Integer, Integer> smaller,
			Map<Integer, Integer> index, List<Integer> list) {

		int smallerS, biggerB;
		smallerS = smaller.get(x);
		biggerB = bigger.get(x);
		int low = 0, mid, high = list.size() - 1, b = 0, s = 0;
		while (low <= high) {
			mid = (low + high) / 2;
			if (index.get(x) == mid) {
				break;
			} else if (index.get(x) < mid) {
				if (list.get(mid) < x)
					b++;
				else
					biggerB--;
				high = mid - 1;
			} else {
				if (list.get(mid) > x)
					s++;
				else
					smallerS--;
				low = mid + 1;
			}
		}
//		 System.out.println("*** " + smallerS);
//		 System.out.println("*** " + biggerB);
//		 System.out.println("*** " + s);
//		 System.out.println("*** " + b);

		if (smallerS >= 0 && biggerB >= 0 && (s > smallerS || b > biggerB))
			System.out.println(-1);
		else
			System.out.println(Math.max(s, b));

	}

}
