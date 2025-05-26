#include <bits/stdc++.h>
using namespace std;

#define V 4

// Dijkstra Algorithm with time complexity O(NUM_VERTICES^2)
vector<int> dijkstra(int graph[V][V], int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    vector<bool> fin(V, false);
    
    for (int count = 0; count < V - 1; count++) {
        // Pick the vertex with the minimum distance which is not finalized
        int mini = INT_MAX, u = -1;
        for (int i = 0; i < V; i++) {
            if (!fin[i] && dist[i] < mini) {
                mini = dist[i];
                u = i;
            }
        }

        fin[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !fin[v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    return dist;
}

// Dijkstra Algorithm using priority queue
vector<int> dijkstraUsingPQ(int vertices, vector<vector<int> > adj[], int src) {
    // pair: first--->distance, second--->vertex
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    // Insert source itself into priority queue and initialize its distance to 0
    pq.push(make_pair(0, src));
    // Create a distance vector and initialize distance from source to all nodes as infinity
    vector<int> dist(vertices, INT_MAX);
    dist[src] = 0; // Source to source distance is 0
    
    while (!pq.empty()) {
        int u = pq.top().second;    
        pq.pop();
        
        for (auto it : adj[u]) {
            int v = it[0];
            int weight = it[1];
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    
    return dist;
}

int main() {
    int graph[V][V] = { 
        { 0, 50, 100, 0 }, 
        { 50, 0, 30, 200 }, 
        { 100, 30, 0, 20 }, 
        { 0, 200, 20, 0 } 
    };

    int src = 0;
    // dijkstra(graph, src) returns a vector
    vector<int> dist = dijkstra(graph, src);

    for (int x : dist) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
