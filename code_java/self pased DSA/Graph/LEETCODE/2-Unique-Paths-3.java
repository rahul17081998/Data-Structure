/*
Problem: Unique Paths III
Given a grid with obstacles, a start cell (1), an end cell (2), and empty cells (0), find the number of unique paths from start to end that visit every empty cell exactly once.

Approach:
- Find the start cell and count the number of empty cells.
- Use DFS to explore all possible paths, marking cells as visited.
- When reaching the end cell, check if all empty cells have been visited.
- Use backtracking to unmark cells after exploring each path.
*/

import java.util.*;

public class UniquePathsIII {
    private int dfs(int[][] grid, int x, int y, int zero, int currentZero) {
        int n = grid.length, m = grid[0].length;
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == -1) return 0;
        if (grid[x][y] == 2) return (zero == currentZero - 1) ? 1 : 0;
        int temp = grid[x][y];
        grid[x][y] = -1;
        int totalPath = dfs(grid, x, y + 1, zero, currentZero + 1)
            + dfs(grid, x + 1, y, zero, currentZero + 1)
            + dfs(grid, x, y - 1, zero, currentZero + 1)
            + dfs(grid, x - 1, y, zero, currentZero + 1);
        grid[x][y] = temp;
        return totalPath;
    }

    public int uniquePathsIII(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int x = 0, y = 0, zero = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) { x = i; y = j; }
                if (grid[i][j] == 0) zero++;
            }
        }
        return dfs(grid, x, y, zero, 0);
    }
} 