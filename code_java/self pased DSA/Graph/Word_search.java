// Approach:
// Use DFS to recursively match each character of the word in the board.
// For each character, explore all 4 directions (up, down, left, right).
// Mark the current cell as visited temporarily to avoid revisiting in the same path.
// If all characters are matched, return true; otherwise, backtrack and continue searching.

import java.util.Scanner;

public class WordSearch {
    static class Solution {
        private final int[] dx = {0, 1, -1, 0};
        private final int[] dy = {1, 0, 0, -1};

        public boolean DFS(char[][] board, String word, int x, int y, int index) {
            if (index == word.length())
                return true;
            if (x < 0 || x >= board.length || y < 0 || y >= board[0].length || board[x][y] != word.charAt(index))
                return false;

            char temp = board[x][y];
            board[x][y] = '0'; // mark visited

            boolean status = DFS(board, word, x + 1, y, index + 1)
                    || DFS(board, word, x, y + 1, index + 1)
                    || DFS(board, word, x - 1, y, index + 1)
                    || DFS(board, word, x, y - 1, index + 1);

            board[x][y] = temp; // backtrack
            return status;
        }

        public boolean isWordExist(char[][] board, String word) {
            int n = board.length;
            int m = board[0].length;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (board[i][j] == word.charAt(0) && DFS(board, word, i, j, 0))
                        return true;
                }
            }
            return false;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        char[][] board = new char[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] = sc.next().charAt(0);
            }
        }
        String word = sc.next();

        Solution obj = new Solution();
        boolean ans = obj.isWordExist(board, word);
        System.out.println(ans ? 1 : 0);

        sc.close();
    }
}