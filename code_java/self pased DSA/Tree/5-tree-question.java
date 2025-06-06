import java.util.*;

public class BinaryTreeProblems {

    /**
     * Problem: Inorder Traversal of a Binary Tree
     * -------------------------------------------------------------------------
     * Given the root of a binary tree, return its inorder traversal.
     * Inorder traversal visits the left subtree, the root node, then the right subtree.
     *
     * Why this works:
     * The recursive structure naturally matches the tree's hierarchical layout.
     *
     * Steps:
     * 1. Recursively visit the left child.
     * 2. Add the current node's data.
     * 3. Recursively visit the right child.
     */
    public static void inorderTraversal(Node root, List<Integer> result) {
        if (root != null) {
            inorderTraversal(root.left, result);
            result.add(root.data);
            inorderTraversal(root.right, result);
        }
    }

    /**
     * Problem: Preorder Traversal of a Binary Tree
     * -------------------------------------------------------------------------
     * In preorder traversal, we visit the node first, then left and right children.
     *
     * Why this works:
     * Useful for copying trees and prefix expressions.
     *
     * Steps:
     * 1. Add the current node's data.
     * 2. Recursively visit the left child.
     * 3. Recursively visit the right child.
     */
    public static void preorderTraversal(Node root, List<Integer> result) {
        if (root != null) {
            result.add(root.data);
            preorderTraversal(root.left, result);
            preorderTraversal(root.right, result);
        }
    }

    /**
     * Problem: Postorder Traversal of a Binary Tree
     * -------------------------------------------------------------------------
     * In postorder traversal, we visit left and right children first, then the node.
     *
     * Why this works:
     * Useful for deleting trees and postfix expressions.
     *
     * Steps:
     * 1. Recursively visit the left child.
     * 2. Recursively visit the right child.
     * 3. Add the current node's data.
     */
    public static void postorderTraversal(Node root, List<Integer> result) {
        if (root != null) {
            postorderTraversal(root.left, result);
            postorderTraversal(root.right, result);
            result.add(root.data);
        }
    }

    /**
     * Problem: Height of Binary Tree
     * -------------------------------------------------------------------------
     * The height is the number of nodes along the longest path from the root to a leaf.
     *
     * Why this works:
     * It uses recursion to compute depth from bottom-up.
     *
     * Steps:
     * 1. Compute the height of left and right subtree.
     * 2. Return max(left, right) + 1.
     */
    public static int height(Node root) {
        if (root == null) return 0;
        return 1 + Math.max(height(root.left), height(root.right));
    }

    /**
     * Problem: Print Nodes at K Distance from Root
     * -------------------------------------------------------------------------
     * Print all nodes that are k distance from the root.
     *
     * Why this works:
     * It reduces k at each level to reach the target distance.
     *
     * Steps:
     * 1. If k == 0, add node.
     * 2. Recursively call left and right with k-1.
     */
    public static void nodesAtDistanceK(Node root, int k, List<Integer> result) {
        if (root == null) return;
        if (k == 0) {
            result.add(root.data);
            return;
        }
        nodesAtDistanceK(root.left, k - 1, result);
        nodesAtDistanceK(root.right, k - 1, result);
    }

    /**
     * Problem: Left View of Binary Tree
     * -------------------------------------------------------------------------
     * Return the leftmost node at each level.
     *
     * Why this works:
     * Uses preorder traversal and adds the first node at each level.
     *
     * Steps:
     * 1. Track current level.
     * 2. If it's the first node at that level, add it.
     * 3. Recursively process left, then right.
     */
    public static void leftView(Node root, int level, List<Integer> result) {
        if (root == null) return;
        if (result.size() == level) {
            result.add(root.data);
        }
        leftView(root.left, level + 1, result);
        leftView(root.right, level + 1, result);
    }

    /**
     * Problem: Diameter of Binary Tree
     * -------------------------------------------------------------------------
     * The diameter is the length of the longest path between any two nodes.
     *
     * Why this works:
     * Computes depth and diameter simultaneously in a bottom-up way.
     *
     * Steps:
     * 1. For each node, calculate left and right height.
     * 2. Update max diameter as left + right.
     * 3. Return height.
     */
    public static int diameter(Node root) {
        int[] diameter = new int[1];
        heightAndUpdateDiameter(root, diameter);
        return diameter[0] + 1;
    }

    private static int heightAndUpdateDiameter(Node root, int[] diameter) {
        if (root == null) return 0;
        int lh = heightAndUpdateDiameter(root.left, diameter);
        int rh = heightAndUpdateDiameter(root.right, diameter);
        diameter[0] = Math.max(diameter[0], lh + rh);
        return 1 + Math.max(lh, rh);
    }

    /**
     * Problem: Lowest Common Ancestor (LCA) of a Binary Tree
     * -------------------------------------------------------
     * Given a binary tree and two nodes p and q, find their Lowest Common Ancestor (LCA).
     * The LCA of two nodes is the deepest node that has both nodes as descendants.
     *
     * Example:
     *         3
     *        / \
     *       5   1
     *      / \ / \
     *     6  2 0  8
     *       / \
     *      7   4
     * LCA(5,1) = 3
     * LCA(6,4) = 5
     *
     * Approach 1: Recursive DFS (Divide and Conquer)
     * -------------------------------------------------------
     * - Recursively search the tree for nodes p and q.
     * - If current node is null, return null.
     * - If current node is p or q, return current node.
     * - Recursively check left and right subtrees.
     * - If both sides return non-null, current node is LCA.
     * - Otherwise, return the non-null result (p, q, or an ancestor).
     *
     * Why it works:
     * - This bubbles up the found nodes.
     * - The node where p and q are found on different sides is their LCA.
     *
     * Steps:
     * 1. Traverse the tree recursively.
     * 2. Return current node if it matches p or q.
     * 3. Get left and right recursive results.
     * 4. If both non-null, return current node.
     * 5. Else return whichever is non-null.
     *
     * Time Complexity: O(N) - visit each node once.
     * Space Complexity: O(H) - recursion stack height.
     *
     * Approach 2: Path Finding from Root to Target Nodes
     * -------------------------------------------------------
     * - Find path from root to node p and store it in a list.
     * - Find path from root to node q similarly.
     * - Traverse both paths until values differ.
     * - The last common node in both paths is the LCA.
     *
     * Why it works:
     * - The paths from root to p and q share a common prefix that ends at the LCA.
     *
     * Steps:
     * 1. Use a helper function to find path from root to target node and store path.
     * 2. Do this for both p and q.
     * 3. Compare both paths node by node.
     * 4. The last matched node is the LCA.
     *
     * Time Complexity: O(N) to find both paths + O(H) to compare.
     * Space Complexity: O(H) for storing each path.
     *
     * Comparison:
     * - Approach 1 is more space efficient and usually preferred.
     * - Approach 2 is intuitive and useful if paths are needed for other purposes.
     */
    public static Node lowestCommonAncestor(Node root, Node p, Node q) {
        if (root == null || root == p || root == q) return root;
        Node left = lowestCommonAncestor(root.left, p, q);
        Node right = lowestCommonAncestor(root.right, p, q);
        if (left == null) return right;
        if (right == null) return left;
        return root;
    }

    /**
    Problem: Burning Tree
    --------------------------------------------------------------
    Given a binary tree and a target node, the goal is to determine
    the **minimum time** required to **burn the entire tree** if the fire
    starts from the **target node**.

    The fire spreads to all connected nodes in **unit time**, which includes:
    - The parent of the current node
    - The left child of the current node
    - The right child of the current node

    The challenge here is to simulate the spreading of fire across the tree
    in a **level-wise manner** (similar to BFS) and calculate the number
    of levels (i.e., time units) it takes for the fire to reach the furthest node.

    Why This Approach Works:
    --------------------------------------------------------------
    - A binary tree is not a graph with parent references. To simulate fire spreading
      upwards (to parent), we first build a **parent mapping** using BFS.
    - Once we find the target node, we can perform a **multi-source BFS** by
      simulating the spread of fire to:
        - left child
        - right child
        - parent (using the mapping)
    - Every time a new node catches fire, we mark it visited to prevent re-processing.
    - The fire spreads one level at a time (one time unit), and we count how many levels
      it takes to reach all nodes.

    Steps to Solve:
    --------------------------------------------------------------
    1. Traverse the tree to map each node to its parent and identify the target node.
    2. Use BFS starting from the target node, with a visited map to prevent cycles.
    3. In each iteration of BFS (each level), mark nodes as burned and enqueue their neighbors.
    4. Count the levels taken in BFS – this represents the time to burn the entire tree.

    Time Complexity:
    --------------------------------------------------------------
    - O(N) where N is the number of nodes in the tree
    - Each node is visited once for parent mapping and once for burning

    Space Complexity:
    --------------------------------------------------------------
    - O(N) for storing parent map and visited nodes
    */
    public static int minTimeToBurn(Node root, int target) {
        Map<Node, Node> parentMap = new HashMap<>();
        Node targetNode = markParents(root, parentMap, target);
        return burnTime(targetNode, parentMap);
    }

    private static Node markParents(Node root, Map<Node, Node> parentMap, int target) {
        Queue<Node> queue = new LinkedList<>();
        queue.offer(root);
        parentMap.put(root, null);
        Node targetNode = null;

        while (!queue.isEmpty()) {
            Node curr = queue.poll();
            if (curr.data == target) targetNode = curr;
            if (curr.left != null) {
                parentMap.put(curr.left, curr);
                queue.offer(curr.left);
            }
            if (curr.right != null) {
                parentMap.put(curr.right, curr);
                queue.offer(curr.right);
            }
        }
        return targetNode;
    }

    private static int burnTime(Node root, Map<Node, Node> parentMap) {
        Set<Node> visited = new HashSet<>();
        Queue<Node> queue = new LinkedList<>();
        queue.offer(root);
        visited.add(root);
        int time = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();
            boolean burned = false;

            for (int i = 0; i < size; i++) {
                Node curr = queue.poll();
                for (Node neighbor : Arrays.asList(curr.left, curr.right, parentMap.get(curr))) {
                    if (neighbor != null && !visited.contains(neighbor)) {
                        burned = true;
                        visited.add(neighbor);
                        queue.offer(neighbor);
                    }
                }
            }

            if (burned) time++;
        }

        return time;
    }

    // Node class definition
    static class Node {
        int data;
        Node left, right;

        Node(int val) {
            data = val;
            left = right = null;
        }
    }

    // You can write test cases inside main
    public static void main(String[] args) {
        // Create a sample tree and run tests if needed
    }
}