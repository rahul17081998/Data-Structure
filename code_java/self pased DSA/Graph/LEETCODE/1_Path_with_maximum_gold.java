/*
Problem: Path with Maximum Gold
Given a grid of positive integers representing gold amounts, you can start and stop collecting gold from any cell, moving only up, down, left, or right, and never visiting a cell more than once. Find the maximum amount of gold you can collect.

Approach:
- For each cell with gold, start a DFS to explore all possible paths, marking cells as visited.
- Use backtracking to unmark cells after exploring each path.
- Track the maximum gold collected across all paths.
*/

import java.util.*;

public class PathWithMaximumGold {
    private int n, m;
    private int[][] dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    
    private int dfs(int[][] grid, int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] <= 0) return 0;
        int gold = grid[x][y];
        grid[x][y] = -gold; // mark visited
        int maxGold = 0;
        for (int[] d : dirs) {
            int nx = x + d[0], ny = y + d[1];
            maxGold = Math.max(maxGold, dfs(grid, nx, ny));
        }
        grid[x][y] = gold; // unmark
        return gold + maxGold;
    }

    public int getMaximumGold(int[][] grid) {
        n = grid.length;
        m = grid[0].length;
        int maxGold = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    maxGold = Math.max(maxGold, dfs(grid, i, j));
                }
            }
        }
        return maxGold;
    }
} 