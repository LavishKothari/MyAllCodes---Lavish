import java.util.*;

public class LeetCode17 {
    public static void main(String[] args) {
        System.out.println(new LeetCode17().letterCombinations(""));
    }

    private static List<String> mapping = Arrays.asList("", "", "abc",
            "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz");

    public List<String> letterCombinations(String digits) {
        List<String> result = new ArrayList<>();
        Set<String> set = new HashSet<>();

        get(digits, digits.length() - 1, set);

        for (String s : set) {
            result.add(s);
        }
        return result;
    }

    private void get(String digits, int counter, Set<String> result) {
        if (counter < 0) {
            if (digits.length() != 0) // this can be tricky :)
                result.add("");
            return;
        }
        get(digits, counter - 1, result);
        Set<String> tempSet = new HashSet<>(result);
        for (String s : tempSet) {
            String stringForNumber = mapping.get(digits.charAt(counter) - '0');
            for (int i = 0; i < stringForNumber.length(); i++) {
                result.add(s + stringForNumber.charAt(i));
            }
            result.remove(s);
        }

    }

}
