package FEB18;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

public class PERMPAL {
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	public static void main(String[] args) throws NumberFormatException, IOException {
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			printArray(solve(br.readLine()));
		}
	}

	private static void printArray(List<Integer> list) {
		list.stream().forEach(e -> System.out.print(e+1 + " "));
		System.out.println();
	}

	private static List<Integer> solve(String str) {
		if (!isGoodPermPossible(str)) {
			return Arrays.asList(-2);
		}
		List<Integer> result = new ArrayList<Integer>(str.length());
		for (int i = 0; i < str.length(); i++)
			result.add(0);
		Map<Character, List<Integer>> map = getMap(str);
		int front = 0;
		int end = str.length() - 1;
		for (Entry<Character, List<Integer>> element : map.entrySet()) {
			List<Integer> currentIndices = element.getValue();
			for (int i = 0; i < currentIndices.size() && i + 1 < currentIndices.size(); i+=2) {
				int index1=currentIndices.get(i);
				int index2=currentIndices.get(i+1);
				result.set(front, index1);
				result.set(end, index2);
				front++;
				end--;
			}
			if(currentIndices.size()%2==1) {
				result.set(result.size()/2,currentIndices.get((currentIndices.size()-1)));
			}
		}
		return result;
	}

	private static Map<Character, List<Integer>> getMap(String str) {
		Map<Character, List<Integer>> result = new HashMap<>();
		for(int i=0;i<str.length();i++) {
			Character c = str.charAt(i);
			if(result.containsKey(c)) {
				result.get(c).add(i);
			}
			else {
				List<Integer> tempList = new ArrayList<>(Arrays.asList(i));
				result.put(c, tempList);
			}
		}
		return result;
	}

	private static boolean isGoodPermPossible(String str) {
		List<Integer> flag = new ArrayList<>(26);
		for (int i = 0; i < 26; i++)
			flag.add(0);
		for (int i = 0; i < str.length(); i++) {
			int index = ((int) str.charAt(i)) - ((int) 'a');
			flag.set(index, flag.get(index) + 1);
		}
		return flag.stream().filter(e -> e % 2 == 1).count() <= 1;
	}

}
