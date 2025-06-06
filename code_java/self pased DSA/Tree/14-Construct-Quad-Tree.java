/**
 * Problem: Construct Quad Tree from a 2D Grid
 * ---------------------------------------------
 * Given a 2D grid of 0s and 1s, construct a Quad Tree representing the grid.
 * Each node in the Quad Tree represents a region of the grid.
 *
 * Definition of Quad Tree Node:
 * - A leaf node represents a region with all values the same (all 0s or all 1s).
 * - A non-leaf node subdivides the region into four equal parts: topLeft, topRight, bottomLeft, bottomRight.
 *
 * Task:
 * Build a Quad Tree from the grid where each node corresponds to a region.
 * Leaf nodes hold the value (true for 1, false for 0) and mark isLeaf = true.
 * Non-leaf nodes have isLeaf = false and references to four children.
 *
 * Approach: Divide and Conquer (Recursive)
 * ---------------------------------------------
 * - Check if all values in the current sub-grid are the same.
 *   - If yes, create a leaf node with that value.
 *   - Else, split the grid into four equal quadrants and recursively build nodes for each quadrant.
 * - Combine the four child nodes into a parent node.
 *
 * Why it works:
 * - Quad Tree structure naturally represents spatial partitioning.
 * - Recursion breaks down the problem into smaller subproblems until uniform regions are found.
 * - This guarantees minimal tree size since uniform regions are combined into single leaf nodes.
 *
 * Steps to solve:
 * 1. Define base case: If sub-grid is uniform, create leaf node.
 * 2. Else, divide grid into four parts:
 *    topLeft, topRight, bottomLeft, bottomRight.
 * 3. Recursively construct Quad Trees for these four parts.
 * 4. Create a parent node with these four children and isLeaf = false.
 *
 * Time Complexity:
 * Worst case O(N^2 log N) where N is grid length.
 * - Checking uniformity in a sub-grid is O(k^2) for sub-grid size k.
 * - Recursion depth ~ log N (halving grid each step).
 *
 * Space Complexity:
 * O(N^2) for the recursion stack and output tree in worst case.
 */

class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;

    public Node() {
        this.val = false;
        this.isLeaf = false;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }

    public Node(boolean val, boolean isLeaf) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }

    public Node(boolean val, boolean isLeaf, Node topLeft, Node topRight, Node bottomLeft, Node bottomRight) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = topLeft;
        this.topRight = topRight;
        this.bottomLeft = bottomLeft;
        this.bottomRight = bottomRight;
    }
}

public class Solution {

    private Node constructQuadTree(int[][] grid, int rowStart, int rowEnd, int colStart, int colEnd) {
        if (rowStart > rowEnd || colStart > colEnd) {
            return null;
        }

        // Check if all values in current sub-grid are same
        boolean isLeaf = true;
        int val = grid[rowStart][colStart];
        outerLoop:
        for (int i = rowStart; i <= rowEnd; i++) {
            for (int j = colStart; j <= colEnd; j++) {
                if (grid[i][j] != val) {
                    isLeaf = false;
                    break outerLoop;
                }
            }
        }

        if (isLeaf) {
            // Leaf node represents uniform grid area
            return new Node(val == 1, true);
        }

        // Otherwise, split grid into four equal parts and recurse
        int rowMid = (rowStart + rowEnd) / 2;
        int colMid = (colStart + colEnd) / 2;

        Node topLeft = constructQuadTree(grid, rowStart, rowMid, colStart, colMid);
        Node topRight = constructQuadTree(grid, rowStart, rowMid, colMid + 1, colEnd);
        Node bottomLeft = constructQuadTree(grid, rowMid + 1, rowEnd, colStart, colMid);
        Node bottomRight = constructQuadTree(grid, rowMid + 1, rowEnd, colMid + 1, colEnd);

        // Parent node with four children, not a leaf
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }

    public Node construct(int[][] grid) {
        int n = grid.length;
        return constructQuadTree(grid, 0, n - 1, 0, n - 1);
    }
}