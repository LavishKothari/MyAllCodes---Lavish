package hackerEarth_november_circuits_17;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Random;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class CostOfArray {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static Random r = new Random();
	static Solution tempSolution = new Solution();

	public static void main(String[] args) throws IOException {
		int n = Integer.parseInt(br.readLine());

		StringTokenizer stz1 = new StringTokenizer(br.readLine());
		StringTokenizer stz2 = new StringTokenizer(br.readLine());

		long[] a = new long[n];
		long[] b = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = Long.parseLong(stz1.nextToken());
			b[i] = Long.parseLong(stz2.nextToken());
		}
		int m = Integer.parseInt(br.readLine());
		long[][] cost = new long[m][m];
		for (int i = 0; i < m; i++) {
			StringTokenizer stz = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				cost[i][j] = Long.parseLong(stz.nextToken());
			}
		}

		solve(n, a, b, m, cost);
	}

	private static void solve(int n, long[] a, long[] b, int m, long[][] cost) {
		Solution solution = new Solution();

		ArrayList<Pair> al, bl;
		al = new ArrayList<>(a.length);
		bl = new ArrayList<>(a.length);
		for (int i = 0; i < a.length; i++) {
			al.add(new Pair(a[i], i));
			bl.add(new Pair(b[i], i));
		}

		Collections.sort(al);
		Collections.sort(bl);

		Set<Integer> set = new HashSet<>();
		for (int i = a.length - 1; i >= 0; i--) {
			int i1 = (int) bl.get(i).b;
			int i2 = (int) al.get(i).b;

			if (set.contains(i1) || set.contains(i2)) {

			} else {
				set.add(i1);
				set.add(i2);
				solution.x.add(i1 + 1);
				solution.y.add(i2 + 1);
			}
		}
		solution.swaps = solution.x.size();
//		System.out.println(solution);
		System.out.println(solution.swaps);
		for(int i=0;i<solution.swaps;i++) {
			System.out.println(solution.x.get(i)+" "+solution.y.get(i));
		}
	}
}

class Pair implements Comparable<Pair> {
	long a, b;

	public Pair(long a, long b) {
		super();
		this.a = a;
		this.b = b;
	}

	@Override
	public String toString() {
		return "(" + a + "," + b + ")";
	}

	@Override
	public int compareTo(Pair o) {
		if (this.a < o.a)
			return -1;
		if (this.a > o.a)
			return 1;
		if (this.b < o.b)
			return -1;
		if (this.b > o.b)
			return 1;
		return 0;
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + (int) (a ^ (a >>> 32));
		result = prime * result + (int) (b ^ (b >>> 32));
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Pair other = (Pair) obj;
		if (a != other.a)
			return false;
		if (b != other.b)
			return false;
		return true;
	}
}

class Solution {
	int swaps;
	ArrayList<Integer> x, y;

	public Solution() {
		super();
		this.swaps = 0;
		this.x = new ArrayList<>();
		this.y = new ArrayList<>();
	}

	@Override
	public String toString() {
		String result = swaps + "\n";
		for (int i = 0; i < x.size(); i++) {
			result = result + x.get(i) + " " + y.get(i) + "\n";
		}
		return result;
	}
}
