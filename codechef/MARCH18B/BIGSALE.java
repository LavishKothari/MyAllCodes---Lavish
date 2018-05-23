package MARCH18B;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class BIGSALE {

	private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer stz;

	public static void main(String[] args) throws NumberFormatException, IOException {
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			int n = Integer.parseInt(br.readLine());
			List<Integer> price = new ArrayList<>(n);
			List<Integer> quantity = new ArrayList<>(n);
			List<Integer> discount = new ArrayList<>(n);
			for (int i = 0; i < n; i++) {
				stz = new StringTokenizer(br.readLine());
				price.add(Integer.parseInt(stz.nextToken()));
				quantity.add(Integer.parseInt(stz.nextToken()));
				discount.add(Integer.parseInt(stz.nextToken()));
			}
			solve(price, quantity, discount);
		}
	}

	private static void solve(List<Integer> price, List<Integer> quantity, List<Integer> discount) {
		double answer = 0.0;
		for (int i = 0; i < price.size(); i++) {
			double newPrice = price.get(i).intValue() + getXPercent(price.get(i), discount.get(i));
			newPrice = newPrice - getXPercent(newPrice, discount.get(i));
			answer = answer + (price.get(i) - newPrice) * quantity.get(i);
		}
		System.out.println(answer);
	}

	private static double getXPercent(double n, double x) {
		return (double) n * x / 100.0;
	}
}
