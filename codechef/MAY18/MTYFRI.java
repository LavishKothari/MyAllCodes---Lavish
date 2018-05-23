package MAY18;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class MTYFRI {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			StringTokenizer stz = new StringTokenizer(br.readLine());

			int n = Integer.parseInt(stz.nextToken());
			int k = Integer.parseInt(stz.nextToken());

			stz = new StringTokenizer(br.readLine());
			List<Integer> odd = new ArrayList<>();
			List<Integer> even = new ArrayList<>();

			for (int i = 0; i < n; i++) {
				if (i % 2 == 0)
					even.add(Integer.parseInt(stz.nextToken()));
				else
					odd.add(Integer.parseInt(stz.nextToken()));
			}
			Collections.sort(even);
			Collections.reverse(even);
			Collections.sort(odd);
			for (int i = 0; i < k && i < odd.size() && i < even.size(); i++) {
				if (odd.get(i) < even.get(i)) {
					swap(odd, even, i);
				} else {
					break;
				}
			}

			if (odd.stream().reduce(0, (x, y) -> x + y) > even.stream().reduce(0, (x, y) -> x + y))
				System.out.println("YES");
			else
				System.out.println("NO");
		}
	}

	private static void swap(List<Integer> odd, List<Integer> even, int i) {
		int fromOdd = odd.get(i);
		int fromEven= even.get(i);
		even.set(i, fromOdd);
		odd.set(i, fromEven);
	}

}
