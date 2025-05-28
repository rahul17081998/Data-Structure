import java.util.*;

class Graph {
    private boolean[][] adjMatrix;
    private int numVertices;

    // Constructor
    public Graph(int numVertices) {
        this.numVertices = numVertices;
        adjMatrix = new boolean[numVertices][numVertices];

        // By default, all elements are false, so no need to initialize explicitly
    }

    // Add an edge
    public void addEdge(int i, int j) {
        adjMatrix[i][j] = true;
        adjMatrix[j][i] = true;
    }

    // Remove an edge
    public void removeEdge(int i, int j) {
        adjMatrix[i][j] = false;
        adjMatrix[j][i] = false;
    }

    // Print the adjacency matrix
    public void printAdjMat() {
        for (int i = 0; i < numVertices; i++) {
            System.out.print(i + " : ");
            for (int j = 0; j < numVertices; j++) {
                System.out.print((adjMatrix[i][j] ? 1 : 0) + " ");
            }
            System.out.println();
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Graph g = new Graph(4);
        g.addEdge(0, 3);
        g.addEdge(1, 3);
        g.addEdge(0, 2);
        g.addEdge(1, 0);
        g.addEdge(2, 1);

        // Print adjacency matrix
        g.printAdjMat();

        // Remove an edge
        System.out.println();
        g.removeEdge(1, 3);
        g.printAdjMat();
    }
}