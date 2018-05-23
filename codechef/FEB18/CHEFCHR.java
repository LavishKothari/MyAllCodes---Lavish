package FEB18;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class CHEFCHR {
	private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	public static void main(String[] args) throws NumberFormatException, IOException {
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			String s = br.readLine();
			solve(s);
		}
	}

	private static void solve(String s) {
		int answer = 0;
		for (int i = 0; i < s.length(); i++)
			if (isChefMaking(s.substring(i, Math.min(i + 4, s.length()))))
				answer++;

		if (answer == 0)
			System.out.println("normal");

		else
			System.out.println("lovely " + answer);
	}

	private static boolean isChefMaking(String s) {
		if (s.length() == 4) {
			boolean c, h, e, f;
			c = h = e = f = false;
			for (int i = 0; i < s.length(); i++) {
				if (s.charAt(i) == 'c')
					c = true;
				else if (s.charAt(i) == 'h')
					h = true;
				else if (s.charAt(i) == 'e')
					e = true;
				else if (s.charAt(i) == 'f')
					f = true;

			}
			return c && h && e && f;
		} else
			return false;
	}
}