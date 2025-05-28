import java.util.*;
/*
 Approach:
 Find articulation points (cut vertices) in an undirected graph using DFS.
 - Perform DFS traversal while keeping track of:
    - discovery time (disc): time when a node is first visited
    - low value (low): earliest visited vertex reachable from subtree rooted at that node
 - For each node, if it is root and has two or more children, it is an articulation point.
 - If it is not root and there exists a child v such that low[v] >= disc[u], then u is an articulation point.
 - Use arrays to track visited nodes, discovery times, low values, and articulation point flags.
 - Traverse all disconnected components to cover the entire graph.
*/

public class ArticulationPoints {
    private int V;
    private List<List<Integer>> adj;

    private int time = 0;

    public ArticulationPoints(int V) {
        this.V = V;
        adj = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }
    }

    // Add undirected edge
    public void addEdge(int u, int v) {
        adj.get(u).add(v);
        adj.get(v).add(u);
    }

    // Recursive DFS utility to find articulation points
    private void APUtil(int u, boolean[] visited, int[] disc, int[] low, int parent, boolean[] isAP) {
        visited[u] = true;
        disc[u] = low[u] = ++time;
        int children = 0;

        for (int v : adj.get(u)) {
            if (!visited[v]) {
                children++;
                APUtil(v, visited, disc, low, u, isAP);

                low[u] = Math.min(low[u], low[v]);

                // If u is not root and low[v] >= disc[u], u is an articulation point
                if (parent != -1 && low[v] >= disc[u]) {
                    isAP[u] = true;
                }
            } else if (v != parent) {
                // Update low value of u for back edge
                low[u] = Math.min(low[u], disc[v]);
            }
        }

        // If u is root and has two or more children, u is articulation point
        if (parent == -1 && children > 1) {
            isAP[u] = true;
        }
    }

    // Function to find and print articulation points
    public void findArticulationPoints() {
        boolean[] visited = new boolean[V];
        int[] disc = new int[V];
        int[] low = new int[V];
        boolean[] isAP = new boolean[V];

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                APUtil(i, visited, disc, low, -1, isAP);
            }
        }

        System.out.print("Articulation points are: ");
        for (int i = 0; i < V; i++) {
            if (isAP[i]) {
                System.out.print(i + " ");
            }
        }
        System.out.println();
    }

    public static void main(String[] args) {
        // First graph example
        ArticulationPoints graph1 = new ArticulationPoints(5);
        graph1.addEdge(1, 0);
        graph1.addEdge(0, 2);
        graph1.addEdge(2, 1);
        graph1.addEdge(0, 3);
        graph1.addEdge(3, 4);
        System.out.println("Articulation points in first graph:");
        graph1.findArticulationPoints();

        // Second graph example
        ArticulationPoints graph2 = new ArticulationPoints(7);
        graph2.addEdge(0, 1);
        graph2.addEdge(1, 2);
        graph2.addEdge(2, 0);
        graph2.addEdge(1, 3);
        graph2.addEdge(1, 4);
        graph2.addEdge(1, 6);
        graph2.addEdge(3, 5);
        graph2.addEdge(4, 5);
        System.out.println("Articulation points in second graph:");
        graph2.findArticulationPoints();
    }
}