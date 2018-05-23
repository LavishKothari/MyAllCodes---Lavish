import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class ZCO12004 {

	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer stz;

	public static void main(String[] args) throws IOException {
		int n = Integer.parseInt(br.readLine());
		int[] arr = new int[n];
		stz = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(stz.nextToken());
		}
		System.out.println(solve(arr));
	}

	private static int solve(int[] arr) {
		if (arr.length == 1)
			return 0;
		if (arr.length == 2)
			return arr[0] < arr[1] ? arr[0] : arr[1];
		int a = arr[0] + arr[1], b = arr[0], c = arr[1];
		for (int i = 2; i < arr.length; i++) {
			int preva = a;
			int prevb = b;
			int prevc = c;

			b = preva < prevc ? preva : prevc;
			c = prevb + arr[i];
			a = prevc + arr[i];
		}
		return b>c?c:b;
	}
}
