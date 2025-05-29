/*
Problem: Diagonal Traversal of a Matrix
Given a matrix, return all elements of the matrix in diagonal order (zigzag level order traversal).

Approach:
- Use BFS to traverse the matrix level by level, alternating the order of each level (reverse every other level).
- Use a queue to process nodes and a visited matrix to avoid revisiting.
- Collect the result in a list.
*/

import java.util.*;

public class DiagonalTraversal {
    public List<Integer> findDiagonalOrder(int[][] mat) {
        int n = mat.length, m = mat[0].length;
        int[] dirx = {0, 1};
        int[] diry = {1, 0};
        boolean[][] vis = new boolean[n][m];
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> ans = new ArrayList<>();
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{0, 0});
        vis[0][0] = true;
        boolean flag = false;
        while (!q.isEmpty()) {
            int size = q.size();
            List<Integer> level = new ArrayList<>();
            for (int i = 0; i < size; i++) {
                int[] v = q.poll();
                int x = v[0], y = v[1];
                level.add(mat[x][y]);
                for (int d = 0; d < 2; d++) {
                    int nx = x + dirx[d], ny = y + diry[d];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
                        q.offer(new int[]{nx, ny});
                        vis[nx][ny] = true;
                    }
                }
            }
            if (flag) {
                res.add(level);
                flag = false;
            } else {
                Collections.reverse(level);
                res.add(level);
                flag = true;
            }
        }
        for (List<Integer> v : res) {
            ans.addAll(v);
        }
        return ans;
    }
} 