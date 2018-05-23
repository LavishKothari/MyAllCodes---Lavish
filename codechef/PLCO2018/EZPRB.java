package PLCO2018;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class EZPRB {
	public final static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	public static void main(String[] args) throws IOException {
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			int n = Integer.parseInt(br.readLine());
			for (int i = 0; i < n; i++)
				System.out.print("a");
			System.out.println();
		}
	}

}
