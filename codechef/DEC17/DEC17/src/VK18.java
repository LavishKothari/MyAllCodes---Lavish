import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class VK18 {
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	static final int MAX = 2 * 1000010;
	static final int N = 1000005;
	private static long[] sum, answer;

	public static void main(String[] args) throws IOException {
		populate();
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			System.out.println(answer[Integer.parseInt(br.readLine())]);
		}
	}

	private static void populate() {
		sum = new long[MAX];
		answer = new long[MAX];
		for (int i = 2; i < MAX; i++) {
			sum[i] = sum[i - 1] + calDiamonds(i);
		}
		answer[1] = 2;
		for (int i = 2; i < N; i++) {
			// 2*(sum from i+1 to 2*i-1) + calDiamonds(2*i)
			answer[i] = answer[i - 1] + 2 * (sum[2 * i - 1] - sum[i]) + calDiamonds(2 * i);
		}
	}

	private static long calDiamonds(int n) {
		int oddSum = 0, evenSum = 0;
		while (n != 0) {
			if (n % 2 == 0)
				evenSum += n % 10;
			else
				oddSum += n % 10;
			n /= 10;
		}
		return Math.abs(oddSum - evenSum);
	}
}
