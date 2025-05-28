import java.util.*;
/*
 Approach:
 Kosaraju's algorithm finds strongly connected components (SCCs) in a directed graph.
 Steps:
 1. Perform DFS on the original graph, pushing nodes onto a stack in order of completion time.
 2. Transpose the graph by reversing all edges.
 3. Perform DFS on the transposed graph in the order defined by the stack.
    Each DFS traversal in this step produces one strongly connected component.
*/
public class KosarajuSCC {

    static void dfs(int node, Stack<Integer> stack, boolean[] visited, List<List<Integer>> adj) {
        visited[node] = true;
        for (int nbr : adj.get(node)) {
            if (!visited[nbr]) {
                dfs(nbr, stack, visited, adj);
            }
        }
        stack.push(node);
    }

    static void revDfs(int node, boolean[] visited, List<List<Integer>> transpose) {
        System.out.print(node + " ");
        visited[node] = true;
        for (int nbr : transpose.get(node)) {
            if (!visited[nbr]) {
                revDfs(nbr, visited, transpose);
            }
        }
    }

    public static void main(String[] args) {
        int n = 6; // number of nodes
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) adj.add(new ArrayList<>());

        // Build the graph
        adj.get(1).add(3);
        adj.get(2).add(1);
        adj.get(3).add(2);
        adj.get(3).add(5);
        adj.get(4).add(6);
        adj.get(5).add(4);
        adj.get(6).add(5);

        // Step 1: DFS to fill stack according to finishing times
        Stack<Integer> stack = new Stack<>();
        boolean[] visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, stack, visited, adj);
            }
        }

        // Step 2: Transpose the graph
        List<List<Integer>> transpose = new ArrayList<>();
        for (int i = 0; i < n; i++) transpose.add(new ArrayList<>());
        for (int i = 0; i < n; i++) {
            for (int nbr : adj.get(i)) {
                transpose.get(nbr).add(i);
            }
        }

        // Step 3: DFS according to finishing times on transposed graph
        Arrays.fill(visited, false);
        while (!stack.isEmpty()) {
            int node = stack.pop();
            if (!visited[node]) {
                System.out.print("SCC: ");
                revDfs(node, visited, transpose);
                System.out.println();
            }
        }
    }
}