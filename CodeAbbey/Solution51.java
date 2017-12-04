package codeabbey;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;
import java.util.Random;
import java.util.StringTokenizer;

public class Solution51 {

	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	public static int[] getArray() throws IOException {
		int[] arr = new int[100];
		StringTokenizer stz = new StringTokenizer(br.readLine());
		int counter = 0;
		while (stz.hasMoreTokens()) {
			int currentElement = Integer.parseInt(stz.nextToken());
			if (currentElement != 0)
				arr[counter++] = currentElement;
		}
		return arr;
	}

	public static void main(String[] args) throws IOException {
		System.out.print(solve(getArray()));
		System.out.print(solve(getArray()));
		System.out.print(solve(getArray()));

	}

	private static int findMin(int[] array) {
		int min = Integer.MAX_VALUE;
		for (int i = 0; i < array.length; i++)
			if (array[i] < min)
				min = array[i];
		return min;
	}

	private static int findMax(int[] array) {
		int max = Integer.MIN_VALUE;
		for (int i = 0; i < array.length; i++)
			if (array[i] > max)
				max = array[i];
		return max;
	}

	private static String solve(int[] array) {
		int min = findMin(array);
		int max = findMax(array);

		int numberOfDice = 5;
		int[] sides = { 2, 4, 6, 8, 10, 12 };

		double overallMin = Double.MAX_VALUE;
		int resultDice = 0, resultSides = 0;
		for (int i = 1; i <= numberOfDice; i++) {

			int minSumPossible = i;
			if (minSumPossible > min)
				continue;

			for (int j = 0; j < sides.length; j++) {

				int maxSumPossible = i * sides[j];
				if (maxSumPossible < max)
					continue;

				HashMap<Integer, Double> ideal = getProbabilityForIdeal(i, sides[j]);
				HashMap<Integer, Double> obtained = getProbabilityForObtained(array);

				int con1 = getElementWithHighestProbability(ideal);
				int con2 = getElementWithHighestProbability(obtained);

				double r = rms((double) con1, (double) con2);
				//
				// if (r < overallMin) {
				// overallMin = r;
				// resultDice = i;
				// resultSides = sides[j];
				// }

				double finalValue = 0.0;
				for (int k = 1; k < numberOfDice * sides.length; k++) {
					double x = ideal.containsKey(k) ? ideal.get(k) : 0;
					double y = obtained.containsKey(k) ? obtained.get(k) : 0;
					double add = rms(x, y);
					if (k == con1)
						add = add * 1.1;
					// System.out.println("sum = "+k+" => "+x+" "+y);
					finalValue += add;
				}
				// System.out.println(i + " " + sides[j] + " rms = " + finalValue);

				if (finalValue < overallMin) {
					overallMin = finalValue;
					resultDice = i;
					resultSides = sides[j];
				}
			}
		}

		return resultDice + "d" + resultSides + " ";
	}

	private static int getElementWithHighestProbability(HashMap<Integer, Double> ideal) {
		int x = 0;
		double y = Double.MIN_VALUE;
		for (Map.Entry<Integer, Double> entry : ideal.entrySet()) {
			if (entry.getValue() > y) {
				x = entry.getKey();
				y = entry.getValue();
			}
		}
		return x;
	}

	private static double rms(Double double1, Double double2) {
		return ((double2 - double1) * (double2 - double1));
	}

	private static HashMap<Integer, Double> getProbabilityForObtained(int[] array) {
		HashMap<Integer, Double> result = new HashMap<>();
		for (int i = 0; i < array.length; i++) {
			if (result.containsKey(array[i])) {
				Double current = result.get(array[i]);
				result.remove(array[i]);
				result.put(array[i], current + 1);
			} else {
				result.put(array[i], 1.0);
			}
		}

		for (Map.Entry<Integer, Double> entry : result.entrySet()) {
			entry.setValue(entry.getValue() / array.length);
		}

		return result;
	}

	private static HashMap<Integer, Double> getProbabilityForIdeal(int numberOfDice, int numberOfSides) {
		HashMap<Integer, Double> result = new HashMap<>();

		for (int sum = numberOfDice; sum <= numberOfDice * numberOfSides; sum++) {
			result.put(sum, getActualProbability(sum, numberOfDice, numberOfSides));
		}

		return result;
	}

	private static double getActualProbability(int sum, int numberOfDice, int numberOfSides) {

		if (sum - numberOfSides - 1 < numberOfDice - 1)
			return nck(sum - 1, numberOfDice - 1) / Math.pow(numberOfSides, numberOfDice);
		return (nck(sum - 1, numberOfDice - 1) - numberOfDice * nck(sum - numberOfSides - 1, numberOfDice - 1))
				/ Math.pow(numberOfSides, numberOfDice);

	}

	private static long nck(int n, int k) {
		return factorial(n).divide(factorial(k).multiply(factorial(n - k))).longValue();
	}

	public static BigInteger factorial(int n) {
		BigInteger result = new BigInteger("1");
		for (int i = 1; i < n; i++)
			result = result.multiply(new BigInteger(i + ""));
		return result;
	}
}
