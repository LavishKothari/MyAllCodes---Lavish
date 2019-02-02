public class LeetCode36 {
    public boolean isValidSudoku(char[][] board) {
        // checking rows.
        for (int i = 0; i < board.length; i++) {
            if (!checkValidArray(board[i]))
                return false;
            if (!checkValidArray(extractColumn(board, i)))
                return false;
            if (!checkValidArray(extractGrid(board, i)))
                return false;
        }
        return true;
    }

    private char[] extractColumn(char[][] board, int col) {
        char[] result = new char[board.length];
        for (int i = 0; i < board.length; i++) {
            result[i] = board[i][col];
        }
        return result;
    }

    private char[] extractGrid(char[][] board, int grid) {
        int counter = 0;
        char[] result = new char[board.length];
        for (int i = grid / 3 * 3; i < grid / 3 * 3 + 3; i++) {
            for (int j = grid % 3 * 3; j < grid % 3 * 3 + 3; j++) {
                result[counter++] = board[i][j];
            }
        }
        return result;
    }

    private boolean checkValidArray(char[] array) {
        boolean[] visited = new boolean[array.length + 1];
        for (int i = 0; i < array.length; i++) {
            if (array[i] != '.') {
                if (visited[array[i] - '0'])
                    return false;
                visited[array[i] - '0'] = true;
            }
        }
        return true;
    }

}
