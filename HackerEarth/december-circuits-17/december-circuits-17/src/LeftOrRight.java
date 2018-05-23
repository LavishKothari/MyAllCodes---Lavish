import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.StringTokenizer;

class LeftOrRight {
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer stz;
	private static ArrayList<HashMap<Integer, Integer>> L, R;
	
	public static void main(String[] args) throws IOException {
		int n, q;
		stz = new StringTokenizer(br.readLine());
		n = Integer.parseInt(stz.nextToken());
		q = Integer.parseInt(stz.nextToken());
		stz = new StringTokenizer(br.readLine());
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(stz.nextToken());
		}

		populate(arr);

		while (q-- > 0) {
			int y, z;
			char d;
			stz = new StringTokenizer(br.readLine());
			y = Integer.parseInt(stz.nextToken());
			z = Integer.parseInt(stz.nextToken());
			d = stz.nextToken().charAt(0);

			System.out.println(solve(arr, y, z, d));
		}
	}

	private static void populate(int[] arr) {
		L = new ArrayList<>(arr.length);
		R = new ArrayList<>(arr.length);

		for (int i = 0; i < arr.length; i++) {
			L.add(new HashMap<Integer, Integer>());
			R.add(new HashMap<Integer, Integer>());
		}
		for (int i = 0; i < arr.length; i++) {
			HashMap<Integer, Integer> currentMap = L.get(i);
			int j = i, distance = 0;
			do {
				if (!currentMap.containsKey(arr[j]))
					currentMap.put(arr[j], distance);
				distance++;

				j = (j - 1 + arr.length) % arr.length;
			} while (j != i);
		}

		for (int i = 0; i < arr.length; i++) {
			HashMap<Integer, Integer> currentMap = R.get(i);
			int j = i, distance = 0;
			do {
				if (!currentMap.containsKey(arr[j]))
					currentMap.put(arr[j], distance);
				distance++;

				j = (j + 1 + arr.length) % arr.length;
			} while (j != i);
		}

	}

	private static int solve(int[] arr, int y, int z, char d) {
		
		HashMap<Integer, Integer> currentMap;
		if (d == 'L')
			currentMap = L.get(y);
		else
			currentMap = R.get(y);

		if (currentMap.containsKey(z))
			return currentMap.get(z);
		else
			return -1;
	}
}
