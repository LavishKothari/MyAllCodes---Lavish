import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class CPLAY {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	public static void main(String[] args) throws IOException {
		String str;
		while ((str = br.readLine()) != null) {
			solve(str);
		}
	}

	private static void solve(String str) {
		if (checkForAdvantage(str))
			return;
		// sudden death
		if (checkForSuddenDeath(str))
			return;
		System.out.println("TIE");
	}

	private static boolean checkForSuddenDeath(String str) {
		int chefGoal = 0, otherGoal = 0;
		for (int i = 10; i < 20; i++) {
			char c = str.charAt(i);
			if (i % 2 == 0) {
				if (c == '1')
					chefGoal++;
			} else {
				if (c == '1')
					otherGoal++;
				if(chefGoal > otherGoal) {
					System.out.println("TEAM-A " + (i + 1));
					return true;
				}
				else if(otherGoal > chefGoal) {
					System.out.println("TEAM-B " + (i + 1));
					return true;
				}
			}
		}
		return false;
	}

	private static boolean checkForAdvantage(String str) {
		int chefGoal = 0, otherGoal = 0, chefRem = 5, otherRem = 5;
		for (int i = 0; i < 10; i++) {
			char c = str.charAt(i);
			if (i % 2 == 0) {
				chefRem--;
				if (c == '1')
					chefGoal++;
			} else {
				otherRem--;
				if (c == '1')
					otherGoal++;
			}

			if (chefRem + chefGoal < otherGoal) {
				// other is winner
				System.out.println("TEAM-B " + (i + 1));
				return true;
			} else if (otherRem + otherGoal < chefGoal) {
				// chef is the winner
				System.out.println("TEAM-A " + (i + 1));
				return true;
			}
		}
		return false;
	}
}
