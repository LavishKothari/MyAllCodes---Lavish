import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Random;
import java.util.StringTokenizer;

class Pair<L, R> {

	private L l;
	private R r;

	public Pair(L l, R r) {
		super();
		this.l = l;
		this.r = r;
	}

	public L getL() {
		return l;
	}

	public void setL(L l) {
		this.l = l;
	}

	public R getR() {
		return r;
	}

	public void setR(R r) {
		this.r = r;
	}

	@Override
	public String toString() {
		return "Pair [l=" + l + ", r=" + r + "]";
	}

}

class CHEFHAM {

	private static Random rnd = new Random();
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private final static int MAX = 100000;
	private volatile static ArrayList<Pair<Integer, Integer>> indices = new ArrayList<>(MAX + 1);
	private static HashSet<Integer> two = new HashSet<>();

	public static void main(String[] args) throws IOException {
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			populate();
			int n = Integer.parseInt(br.readLine());
			int[] arr = new int[n];
			StringTokenizer stz = new StringTokenizer(br.readLine());
			for (int i = 0; i < n; i++) {
				arr[i] = Integer.parseInt(stz.nextToken());
				fillIndices(arr[i], i);
			}
			solve(arr);
		}
	}

	private static void fillIndices(int element, int index) {
		if (indices.get(element).getL().intValue() == -1) {
			indices.get(element).setL(index);
		} else {
			indices.get(element).setR(index);
			two.add(element);

		}
	}

	private static void populate() {
		two = new HashSet<>();
		indices = new ArrayList<>(MAX + 1);
		for (int i = 0; i < MAX + 1; i++) {
			indices.add(new Pair<Integer, Integer>(-1, -1));
		}
	}

	private static void solve(int[] arr) {
		if (arr.length == 1 || (arr.length == 2 && arr[0] == arr[1])) {
			printSolution(arr, arr);
			return;
		} else if (arr.length == 2) {
			int[] tempArr = new int[2];
			tempArr[0] = arr[1];
			tempArr[1] = arr[0];
			printSolution(arr, tempArr);
			return;
		}

		boolean[] isTaken = new boolean[arr.length];
		boolean[] isDone = new boolean[arr.length];
		int[] brr = new int[arr.length];
		while (two.size() > 1) {
			int first = -1, second = -1;
			int counter = 0;
			for (Iterator<Integer> it = two.iterator(); it.hasNext(); counter++) {
				if (counter == 0)
					first = it.next();
				else if (counter == 1)
					second = it.next();
				else
					break;
			}

			int a = indices.get(first).getL();
			int b = indices.get(first).getR();
			int c = indices.get(second).getL();
			int d = indices.get(second).getR();

			brr[a] = arr[c];
			brr[b] = arr[d];
			brr[c] = arr[a];
			brr[d] = arr[b];

			isTaken[a] = isTaken[b] = isTaken[c] = isTaken[d] = true;
			isDone[a] = isDone[b] = isDone[c] = isDone[d] = true;

			two.remove(first);
			two.remove(second);
		}

		// printSolution(arr, brr);
		// System.out.println(two.size());

		if (two.size() == 1) {
			int counter = 0, ele = -1;
			for (Iterator<Integer> it = two.iterator(); it.hasNext(); counter++) {
				if (counter == 0)
					ele = it.next();
				else
					break;
			}

			int index1 = indices.get(ele).getL();
			int index2 = indices.get(ele).getR();

			int x = -1, y = -1;
			for (int i = 0; i < arr.length; i++) {
				if (isTaken[i] || i == index1 || i == index2)
					continue;
				if (x == -1)
					x = i;
				else if (y == -1)
					y = i;
				else
					break;
			}
			if (x != -1) {
				brr[index1] = arr[x];
				isTaken[x] = true;
				isDone[index1] = true;
			}
			if (y != -1) {
				brr[index2] = arr[y];
				isTaken[y] = true;
				isDone[index2] = true;
			}
		}

		for (int i = 0; i < brr.length; i++) {
			if (!isDone[i]) {
				int nextIndex = getNextIndex(arr, i, isTaken);
				if (nextIndex != -1) {
					isTaken[nextIndex] = true;
					brr[i] = arr[nextIndex];
				} else {
					int secondNextIndex = getSecondNextIndex(arr, i, isTaken);
					brr[i] = arr[secondNextIndex];
					isTaken[i] = true;
				}
				isDone[i] = true;
			}
		}

		for (int j = 0; j < brr.length; j++) {
			if (brr[j] == arr[j]) {
				for (int i = 0; i < 1000; i++) {
					int x;
					do {
						x = getRandomBetween(0, arr.length - 1);
					} while (x == j);
					if (brr[j] != arr[x] && brr[x] != arr[j]) {
						swapInArray(brr, x, j);
						break;
					}
				}
			}
		}
		printSolution(arr, brr);
	}

	private static void swapInArray(int[] arr, int x, int y) {
		int temp = arr[x];
		arr[x] = arr[y];
		arr[y] = temp;
	}

	// including a and b
	private static int getRandomBetween(int a, int b) {
		int x = rnd.nextInt();
		if (x < 0)
			x = -x;
		return x % (b - a + 1) + a;
	}

	private static int getSecondNextIndex(int[] arr, int index, boolean[] isTaken) {

		int i = index;
		do {
			if (!isTaken[i])
				return i;
			i = (i + 1) % arr.length;
		} while (i != index);
		return -1;
	}

	private static int getNextIndex(int[] arr, int index, boolean[] isTaken) {
		for (int i = (index + 1) % arr.length; i != index; i = (i + 1) % arr.length) {
			if (!isTaken[i] && arr[i] != arr[index])
				return i;
		}
		return -1;
	}

	private static void printSolution(int[] arr, int[] brr) {
		int count = 0;
		for (int i = 0; i < arr.length; i++) {
			if (arr[i] != brr[i])
				count++;
		}
		System.out.println(count);
		for (int i = 0; i < brr.length; i++) {
			System.out.print(brr[i] + " ");
		}
	}

}
