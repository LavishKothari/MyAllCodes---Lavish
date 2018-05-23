package MARCH18B;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class MINEAT {
	private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer stz;

	public static void main(String[] args) throws NumberFormatException, IOException {
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			int n, h;
			stz = new StringTokenizer(br.readLine());
			n = Integer.parseInt(stz.nextToken());
			h = Integer.parseInt(stz.nextToken());

			List<Integer> bananas = new ArrayList<>();
			stz = new StringTokenizer(br.readLine());

			for (int i = 0; i < n; i++) {
				bananas.add(Integer.parseInt(stz.nextToken()));
			}
			solve(bananas, h);
		}

	}

	private static void solve(List<Integer> bananas, int h) {
		int start = 1, end = bananas.stream().reduce(0, Integer::sum);

		while (start <= end) {
			int mid = (start + end) / 2;
			int currentH = findHoursFor(bananas, mid);
			if (currentH > h) {
				start = mid + 1;
			} else if (currentH < h) {
				end = mid - 1;
			} else
				break;
		}
		System.out.println((start+end)/2);
	}

	private static int findHoursFor(List<Integer> bananas, int k) {
		int answer = 0;
		for (final Integer currentValue : bananas) {
			answer += currentValue / k;
			if (currentValue % k != 0)
				answer++;
		}
		return answer;
	}

}
