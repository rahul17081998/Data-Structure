import java.util.*;

/**
 * Tarjan's Algorithm - Finding Strongly Connected Components (SCCs)
 * ------------------------------------------------------------------
 *
 * What is an SCC?
 * ----------------
 * A Strongly Connected Component (SCC) of a directed graph is a maximal set of vertices
 * such that for every pair of vertices u and v in the set:
 *  - There is a path from u to v, and from v to u.
 *
 * What is Tarjan’s Algorithm?
 * ---------------------------
 * Tarjan’s algorithm is a single-pass Depth-First Search (DFS) based method
 * to identify all SCCs in a **directed graph** in **O(V + E)** time.
 *
 * Benefits:
 * ---------
 * ✅ Faster than Kosaraju's (one-pass DFS)
 * ✅ Memory efficient (no graph transposition)
 * ✅ Great for detecting cycles and dependencies
 * ✅ Used in compilers, deadlock detection, social networks, etc.
 *
 * Approach:
 * ---------
 * 1. Perform a DFS traversal of the graph.
 * 2. For each node `u`, assign:
 *    - `disc[u]`: the discovery time of node u
 *    - `low[u]`: the earliest discovered node reachable from u (includes back edges)
 *
 * 3. Push every node visited into a stack. This stack represents the current DFS path.
 * 4. For each adjacent node `v` of `u`:
 *    - If `v` is not visited, recursively call DFS on `v` and update `low[u] = min(low[u], low[v])`
 *    - If `v` is in the current stack (i.e., part of the DFS path), update `low[u] = min(low[u], disc[v])`
 *
 * 5. After visiting all neighbors, if `low[u] == disc[u]`, then:
 *    - `u` is the **root of an SCC**
 *    - Pop all nodes from the stack until `u` is reached
 *    - These popped nodes form one SCC
 *
 * 6. Repeat this for all unvisited nodes.
 *
 * Time Complexity: O(V + E)
 * Space Complexity: O(V)
 */

public class TarjansAlgorithm {

    private int time = 0;                 // Global time counter for DFS
    private List<List<Integer>> adj;     // Adjacency list
    private int V;                       // Number of vertices

    /**
     * Constructor to initialize graph with V vertices
     */
    public TarjansAlgorithm(int V) {
        this.V = V;
        adj = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }
    }

    /**
     * Add a directed edge from u to v
     */
    public void addEdge(int u, int v) {
        adj.get(u).add(v);
    }

    /**
     * Recursive DFS function to compute discovery and low-link values
     * and find SCCs rooted at vertex u
     */
    private void dfsRec(int u, int[] disc, int[] low, Deque<Integer> stack, boolean[] stackMember) {
        disc[u] = low[u] = ++time;
        stack.push(u);
        stackMember[u] = true;

        for (int v : adj.get(u)) {
            if (disc[v] == -1) {
                dfsRec(v, disc, low, stack, stackMember);
                low[u] = Math.min(low[u], low[v]);
            } else if (stackMember[v]) {
                low[u] = Math.min(low[u], disc[v]);
            }
        }

        // If u is the head node of an SCC
        if (low[u] == disc[u]) {
            System.out.print("SCC: ");
            while (stack.peek() != u) {
                int w = stack.pop();
                System.out.print(w + " ");
                stackMember[w] = false;
            }
            int w = stack.pop();
            System.out.println(w);
            stackMember[w] = false;
        }
    }

    /**
     * Main function to find and print all SCCs in the graph
     */
    public void findSCCs() {
        int[] disc = new int[V];          // Discovery times
        int[] low = new int[V];           // Low-link values
        boolean[] stackMember = new boolean[V]; // Whether node is in current DFS stack
        Deque<Integer> stack = new ArrayDeque<>();

        Arrays.fill(disc, -1);
        Arrays.fill(low, -1);

        for (int i = 0; i < V; i++) {
            if (disc[i] == -1) {
                dfsRec(i, disc, low, stack, stackMember);
            }
        }
    }

    /**
     * Example usage with test graphs
     */
    public static void main(String[] args) {
        System.out.println("SCCs in first graph:");
        TarjansAlgorithm g1 = new TarjansAlgorithm(5);
        g1.addEdge(1, 0);
        g1.addEdge(0, 2);
        g1.addEdge(2, 1);
        g1.addEdge(0, 3);
        g1.addEdge(3, 4);
        g1.findSCCs();

        System.out.println("\nSCCs in second graph:");
        TarjansAlgorithm g2 = new TarjansAlgorithm(7);
        g2.addEdge(0, 1);
        g2.addEdge(1, 2);
        g2.addEdge(2, 0);
        g2.addEdge(1, 3);
        g2.addEdge(1, 4);
        g2.addEdge(1, 6);
        g2.addEdge(3, 5);
        g2.addEdge(4, 5);
        g2.findSCCs();
    }
}