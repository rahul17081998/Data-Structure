import java.util.*;

public class Graph {
    private List<List<Integer>> adjList;

    // Constructor
    public Graph(int v) {
        adjList = new ArrayList<>();
        for (int i = 0; i < v; i++) {
            adjList.add(new ArrayList<>());
        }
    }

    // Add an edge
    public void addEdge(int u, int v) {
        adjList.get(u).add(v);
        adjList.get(v).add(u); // because it's an undirected graph
    }

    // Print the graph
    public void printGraph() {
        for (int i = 0; i < adjList.size(); i++) {
            System.out.print("Vertex " + i + ": ");
            for (int node : adjList.get(i)) {
                System.out.print(node + " ");
            }
            System.out.println();
        }
    }

    // Main method
    public static void main(String[] args) {
        int v = 4;
        Graph graph = new Graph(v);
        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(1, 2);
        graph.addEdge(1, 3);

        graph.printGraph();
    }
}