import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class CHEFEXQ {

	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private final static int MAX = 100000;
	private static StringTokenizer stz;

	public static void main(String[] args) throws IOException {

		int n, q;
		stz = new StringTokenizer(br.readLine());
		n = Integer.parseInt(stz.nextToken());
		q = Integer.parseInt(stz.nextToken());

		int[] arr = new int[n];
		stz = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(stz.nextToken());
		}
		while (q-- > 0) {
			int type, a, b;
			stz = new StringTokenizer(br.readLine());
			type = Integer.parseInt(stz.nextToken());
			a = Integer.parseInt(stz.nextToken());
			b = Integer.parseInt(stz.nextToken());
			solve(arr, type, a - 1, b);
		}
	}

	private static void solve(int[] arr, int type, int a, int b) {
		if (type == 1) {
			arr[a] = b;
		} else {
			int answer = 0;
			int currentXOR = arr[0];
			if (currentXOR == b)
				answer++;
			for (int i = 1; i <= a; i++) {
				currentXOR = currentXOR ^ arr[i];
				if (currentXOR == b)
					answer++;
			}
			System.out.println(answer);
		}
	}

}
