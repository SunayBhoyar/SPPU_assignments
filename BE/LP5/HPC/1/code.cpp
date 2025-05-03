#include <iostream>                                                             // For input and output
#include <vector>                                                               // For using std::vector as adjacency list
#include <queue>                                                                // For BFS queue
#include <omp.h>                                                                // OpenMP header for parallel processing

using namespace std;

// Graph class using adjacency list representation
class Graph {
    int V;// Number of vertices
    vector<vector<int>> adj;// Adjacency list

public:
// Constructor to initialize graph with V vertices
    Graph(int V) : V(V), adj(V) {}

    // Function to add a directed edge from v to w
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

private:
    // Utility function for parallel DFS using OpenMP
    void parallelDFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        // Parallelize traversal of adjacent vertices
        #pragma omp parallel for
        for (int i = 0; i < static_cast<int>(adj[v].size()); ++i) {
            int n = adj[v][i];
            bool localVisited = false;

            // Ensure that only one thread checks/updates visited[n] at a time
            #pragma omp critical
            {
                if (!visited[n]) {
                    visited[n] = true;
                    localVisited = true;
                }
            }

            // Recurse only if this thread successfully marked the node
            if (localVisited) {
                parallelDFSUtil(n, visited);
            }
        }
    }

public:
    // Function to start parallel DFS from a starting vertex
    void parallelDFS(int startVertex) {
        vector<bool> visited(V, false);// Track visited nodes

        // Parallel region begins
        #pragma omp parallel
        {
            // Only one thread should initiate the recursion
            #pragma omp single
            {
                parallelDFSUtil(startVertex, visited);
            }
        }
    }

    // Function to perform parallel BFS using OpenMP
    void parallelBFS(int startVertex) {
        vector<bool> visited(V, false);// Track visited nodes
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

         // Standard BFS loop
        while (!q.empty()) {
            int v;

            // Ensure only one thread modifies queue at a time
            #pragma omp critical
            {
                v = q.front();
                q.pop();
            }

            cout << v << " ";

            // Parallelize neighbor processing
            #pragma omp parallel for
            for (int i = 0; i < static_cast<int>(adj[v].size()); ++i) {
                int n = adj[v][i];
                bool localVisited = false;

                // Synchronize access to the shared visited array and queue
                #pragma omp critical
                {
                    if (!visited[n]) {
                        visited[n] = true;
                        q.push(n);
                        localVisited = true;
                    }
                }
            }
        }
    }
};

int main() {
    int V, E;// V = number of vertices, E = number of edges

    // Read number of vertices and edges from user
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Graph g(V);// Create a graph with V vertices

    // Read all edges from user
    cout << "Enter the edges (format: vertex1 vertex2):\n";
    for (int i = 0; i < E; ++i) {
        int v, w;
        cin >> v >> w;
        g.addEdge(v, w);// Add directed edge v -> w
    }

    int startVertex;
    // Read starting vertex for DFS and BFS
    cout << "Enter the starting vertex for DFS and BFS: ";
    cin >> startVertex;

    // Perform and display DFS
    cout << "Depth-First Search (DFS): ";
    g.parallelDFS(startVertex);
    cout << "\n";

    // Perform and display BFS
    cout << "Breadth-First Search (BFS): ";
    g.parallelBFS(startVertex);
    cout << "\n";

    return 0;
}
