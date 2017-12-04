import java.util.Scanner;

class Main {

	private static Scanner sc;

	public static void main(String[] args) {
		sc = new Scanner(System.in);

		int t = sc.nextInt();
		while (t-- > 0) {
			int n = sc.nextInt();
			int[] arr = new int[n];
			for (int i = 0; i < n; i++)
				arr[i] = sc.nextInt();

			int count = 0, m = Integer.MIN_VALUE;
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if (arr[i] + arr[j] > m)
						m = arr[i] + arr[j];
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if (arr[i] + arr[j] == m)
						count++;
				}
			}

			System.out.println((double) count / (n * (n - 1) / 2));
		}
	}
}

