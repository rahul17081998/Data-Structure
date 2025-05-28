import java.util.*;
/*
 Approach:
 Tarjan's Algorithm is used to find Strongly Connected Components (SCCs) in a directed graph.
 - Perform a DFS traversal keeping track of discovery times and low-link values for each vertex.
 - Use a stack to store the vertices of the current DFS path.
 - The low-link value of a node represents the earliest visited vertex reachable from that node.
 - When a node's discovery time equals its low-link value, it is the root of an SCC.
 - Pop all vertices from the stack up to this node to form one SCC.
 - Repeat for all nodes to find all SCCs.
*/
public class TarjansAlgorithm {

    private int time = 0;
    private List<List<Integer>> adj;
    private int V;

    public TarjansAlgorithm(int V) {
        this.V = V;
        adj = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }
    }

    public void addEdge(int u, int v) {
        adj.get(u).add(v);
    }

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

    public void findSCCs() {
        int[] disc = new int[V];
        int[] low = new int[V];
        boolean[] stackMember = new boolean[V];
        Deque<Integer> stack = new ArrayDeque<>();

        Arrays.fill(disc, -1);
        Arrays.fill(low, -1);
        Arrays.fill(stackMember, false);

        for (int i = 0; i < V; i++) {
            if (disc[i] == -1) {
                dfsRec(i, disc, low, stack, stackMember);
            }
        }
    }

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