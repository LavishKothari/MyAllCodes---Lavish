package FEB18;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class CARPTUN {
	private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer stz;

	public static void main(String[] args) throws NumberFormatException, IOException {
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			int n = Integer.parseInt(br.readLine());
			List<Integer> numbers = new ArrayList<>();
			stz = new StringTokenizer(br.readLine());
			for (int i = 0; i < n; i++) {
				numbers.add(Integer.parseInt(stz.nextToken()));
			}
			stz = new StringTokenizer(br.readLine());
			int c = Integer.parseInt(stz.nextToken());
			int d = Integer.parseInt(stz.nextToken());
			int s = Integer.parseInt(stz.nextToken());

			solve(numbers, c, d, s);
		}
	}

	private static void solve(List<Integer> numbers, int c, int d, int s) {
		Integer difference = numbers.stream().reduce(numbers.get(0), (max, e) -> Math.max(max, e));
		System.out.println(String.format("%.8f", (c-1)*(double)difference));
	}

	private static void printArray(double[] arr) {
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}

}
