import java.util.*;

/**
 * What is SCC (Strongly Connected Component)?
 * -------------------------------------------
 * A Strongly Connected Component in a directed graph is a maximal group of vertices such that
 * there is a path from every vertex to every other vertex in the group (i.e., u → v and v → u).
 *
 * What is Kosaraju’s Algorithm?
 * -----------------------------
 * Kosaraju's Algorithm is a graph traversal technique used to find all strongly connected components (SCCs)
 * in a directed graph. It runs in linear time O(V + E), where V is the number of vertices and E is the number of edges.
 *
 * Approach:
 * ---------
 * Kosaraju's Algorithm involves three main steps:
 *
 * 1. **First DFS (Original Graph)**:
 *    - Perform a depth-first search (DFS) on the original graph.
 *    - Track the **finishing time** of each vertex (i.e., when all its descendants are done).
 *    - Push the vertex onto a stack when it finishes.
 *    - The stack stores vertices in **reverse topological order**.
 *
 * 2. **Transpose the Graph**:
 *    - Reverse the direction of all edges in the graph.
 *    - This allows us to explore original components in reverse.
 *
 * 3. **Second DFS (Transposed Graph)**:
 *    - Pop vertices one by one from the stack and perform DFS on the transposed graph.
 *    - Each DFS traversal from an unvisited node gives a complete SCC.
 *
 * Why finishing time matters:
 * ---------------------------
 * Finishing time ensures that when we reverse the graph, we visit the "last completed" nodes first,
 * which guarantees that each DFS in the transposed graph reaches the entire SCC in one go.
 */

public class KosarajuAlgorithm {

    // Adds a directed edge from u to v
    static void addEdge(List<List<Integer>> graph, int u, int v) {
        graph.get(u).add(v);
    }

    // Step 1: DFS to fill stack according to finishing times
    static void dfs(int node, boolean[] visited, Stack<Integer> stack, List<List<Integer>> graph) {
        visited[node] = true;
        for (int neighbor : graph.get(node)) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, stack, graph);
            }
        }
        stack.push(node); // push after all descendants are visited (finishing time)
    }

    // Step 2: Transpose (reverse) the graph
    static List<List<Integer>> transposeGraph(List<List<Integer>> graph, int V) {
        List<List<Integer>> transposed = new ArrayList<>();
        for (int i = 0; i < V; i++) transposed.add(new ArrayList<>());

        for (int u = 0; u < V; u++) {
            for (int v : graph.get(u)) {
                transposed.get(v).add(u); // reverse the edge
            }
        }
        return transposed;
    }

    // Step 3: DFS on transposed graph to collect one SCC
    static void reverseDfs(int node, boolean[] visited, List<Integer> component, List<List<Integer>> transposed) {
        visited[node] = true;
        component.add(node);
        for (int neighbor : transposed.get(node)) {
            if (!visited[neighbor]) {
                reverseDfs(neighbor, visited, component, transposed);
            }
        }
    }

    // Main Kosaraju function to find and print all SCCs
    public static void kosaraju(int V, List<List<Integer>> graph) {
        Stack<Integer> stack = new Stack<>();
        boolean[] visited = new boolean[V];

        // Step 1: Perform DFS and store vertices by finishing time
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, stack, graph);
            }
        }

        // Step 2: Transpose the graph
        List<List<Integer>> transposed = transposeGraph(graph, V);

        // Step 3: Perform DFS on transposed graph in order of finishing time
        Arrays.fill(visited, false);
        System.out.println("Strongly Connected Components:");
        while (!stack.isEmpty()) {
            int node = stack.pop();
            if (!visited[node]) {
                List<Integer> component = new ArrayList<>();
                reverseDfs(node, visited, component, transposed);
                System.out.println(component);
            }
        }
    }

    public static void main(String[] args) {
        int V = 5;
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < V; i++) graph.add(new ArrayList<>());

        // Directed graph
        addEdge(graph, 0, 2);
        addEdge(graph, 2, 1);
        addEdge(graph, 1, 0);
        addEdge(graph, 0, 3);
        addEdge(graph, 3, 4);

        kosaraju(V, graph);
    }
}