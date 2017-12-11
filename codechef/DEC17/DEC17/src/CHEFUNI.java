import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class CHEFUNI {
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer stz;

	public static void main(String[] args) throws IOException {
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			stz = new StringTokenizer(br.readLine());
			int x, y, z, a, b, c;
			x = Integer.parseInt(stz.nextToken());
			y = Integer.parseInt(stz.nextToken());
			z = Integer.parseInt(stz.nextToken());
			a = Integer.parseInt(stz.nextToken());
			b = Integer.parseInt(stz.nextToken());
			c = Integer.parseInt(stz.nextToken());

			solve(x, y, z, a, b, c);

		}

	}

	private static void solve(int X, int Y, int Z, int A, int B, int C) {
		long[][][] dp = new long[X + 1][Y + 1][Z + 1];
		dp[0][0][0] = 0;
		
		for (int i = 0; i <= X; i++) {
			for (int j = 0; j <= Y; j++) {
				for (int k = 0; k <= Z; k++) {
					if (i == 0 && j == 0 && k == 0)
						continue;
					long a, b, c, d, e, f, g;
					a = b = c = d = e = f = g = Long.MAX_VALUE;
					if (i - 1 >= 0) {
						a = dp[i - 1][j][k] + A;
					}
					if (j - 1 >= 0) {
						b = dp[i][j - 1][k] + A;
					}
					if (k - 1 >= 0) {
						c = dp[i][j][k - 1] + A;
					}

					if (i - 1 >= 0 && j - 1 >= 0) {
						d = dp[i - 1][j - 1][k] + B;
					}
					if (i - 1 >= 0 && k - 1 >= 0) {
						e = dp[i - 1][j][k - 1] + B;
					}
					if (k - 1 >= 0 && j - 1 >= 0) {
						f = dp[i][j - 1][k - 1] + B;
					}

					if (i - 1 >= 0 && j - 1 >= 0 && k - 1 >= 0) {
						g = dp[i - 1][j - 1][k - 1] + C;
					}
					
					dp[i][j][k]= min(a,b,c,d,e,f,g);
				}
			}
		}
		System.out.println(dp[X][Y][Z]);
	}

	private static long min(long a, long b, long c, long d, long e, long f, long g) {
		long answer = a;
		answer = answer<b?answer:b;
		answer = answer<c?answer:c;
		answer = answer<d?answer:d;
		answer = answer<e?answer:e;
		answer = answer<f?answer:f;
		answer = answer<g?answer:g;
		
		return answer;
	}

}
