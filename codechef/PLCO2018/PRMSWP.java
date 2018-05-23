package PLCO2018;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.TreeMap;

public class PRMSWP {
	public final static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	public static void main(String[] args) throws IOException {
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			int n = Integer.parseInt(br.readLine());
			Map<Integer,Integer> map=find(n);
			int exponents[]=new int[map.size()];
			int factors[]=new int[map.size()];
			
			int counter=0;
			for(final Entry<Integer, Integer> entry:map.entrySet()) {
				exponents[counter]=entry.getValue();
				factors[counter]=entry.getKey();
				counter++;
			}
		}

	}

	void generate(int[] p, int L, int R) {
		if (L == R) { // all numbers are set
			// do something with permutation in array p[]
		} else { // numbers at positions [0, L-1] are set, try to set L-th position
			for (int i = L; i <= R; i++) {
				int tmp = p[L];
				p[L] = p[i];
				p[i] = tmp;
				generate(p, L + 1, R);
				tmp = p[L];
				p[L] = p[i];
				p[i] = tmp;
			}
		}
	}

	private static Map<Integer, Integer> find(int n) {
		int currentNumber = 2;
		Map<Integer, Integer> map = new TreeMap();
		while (n != 1) {
			while (n % currentNumber == 0) {
				n /= 2;
				if (!map.containsKey(currentNumber)) {
					map.put(currentNumber, 1);
				} else {
					int temp = map.get(currentNumber);
					map.remove(currentNumber);
					map.put(currentNumber, temp + 1);
				}
			}
		}
		return map;
	}

}
