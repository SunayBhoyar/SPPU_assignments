#include<iostream>
#include<vector>
#include<queue>
#include<omp.h>


using namespace std ; 

class Graph{
    int V ;
    vector<vector<int>>adj ; 

    public: 
    Graph(int V) : V(V), adj(V) {}

    void addEdge (int u , int v){
        adj[u].push_back(v); 
    }

    void seqDFS(int v, vector<bool>& visited){
        visited[v] = true ; 
        cout << v << " " ; 
        for (int i = 0 ; i <adj[v].size() ; i ++){
            if(!visited[adj[v][i]]){
                seqDFS(adj[v][i],visited) ; 
            }
        }
    }

    void parlDFS(int v, vector<bool>& visited) {
        visited[v] = true ; 
        cout << v << " "; 
    
        #pragma omp parallel for
        for (int i = 0; i < adj[v].size(); i++){
            int n = adj[v][i];
            bool localVisited = false;
            #pragma omp critical
            {
                if (!visited[n]) {
                    visited[n] = true;
                    localVisited = true;
                }
            }

            if (localVisited) {
                parlDFS(n, visited);
            }
        }
    }
    

    void seqBFS(int v, vector<bool>& visited){
        queue<int> Q ; 
        visited[v] = true ; 
        Q.push(v) ; 

        while(!Q.empty()){
            int curr = Q.front() ; Q.pop() ; 
            cout << curr << " " ; 
            for (int i = 0 ; i <adj[curr].size() ; i ++){
                if(!visited[adj[curr][i]]){
                    visited[adj[curr][i]] = true;
                    Q.push(adj[curr][i]) ; 
                }
            }
        }
    }

    void parlBFS(int v, vector<bool>& visited) {

        queue<int> Q;
        visited[v] = true;
        Q.push(v);
        cout << v << " ";
    
        while (!Q.empty()) {

            int size = Q.size();
            vector<int> levelNodes;
    
            // Collect current level nodes
            for (int i = 0; i < size; ++i) {
                int curr = Q.front(); Q.pop();
    
                #pragma omp parallel for
                for (int j = 0; j < adj[curr].size(); ++j) {
                    int neighbor = adj[curr][j];
                    bool shouldVisit = false;
    
                    #pragma omp critical
                    {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            shouldVisit = true;
                        }
                    }
    
                    if (shouldVisit) {
                        #pragma omp critical
                        {
                            levelNodes.push_back(neighbor);
                        }
                    }
                }
            }
    
            // Print and enqueue the next level's nodes
            for (int node : levelNodes) {
                cout << node << " ";
                Q.push(node);
            }
        }
    }
};

int main() {
    int choice;
    cout << "Choose input method:\n1. Manual\n2. Default Graph\nEnter choice: ";
    cin >> choice;

    Graph g(10); 

    if (choice == 1) {
        int V, E;
        cout << "Enter the number of vertices: ";
        cin >> V;
        cout << "Enter the number of edges: ";
        cin >> E;

        g = Graph(V);

        cout << "Enter the edges (format: vertex1 vertex2):\n";
        for (int i = 0; i < E; ++i) {
            int v, w;
            cin >> v >> w;
            g.addEdge(v, w);
        }
    } else {
        cout << "Using default graph with 10 vertices and the following edges:\n";
        vector<pair<int, int>> edges = {
            {0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5},
            {2, 6}, {3, 7}, {4, 7}, {5, 8}, {6, 9},
            {7, 9}, {8, 9}
        };

        for (auto [v, w] : edges) {
            g.addEdge(v, w);
            cout << v << " -> " << w << endl;
        }
    }

    int startVertex;
    cout << "Enter the starting vertex for DFS and BFS: ";
    cin >> startVertex;

    vector<bool> visited(10, false);
    cout << "Depth-First Search (DFS) sequential : ";
    double start = omp_get_wtime();
    g.seqDFS(startVertex,visited);
    double end = omp_get_wtime();
    cout << "\nTime: " << end - start << " seconds\n\n";
    cout << "\n";
    
    fill(visited.begin(), visited.end(), false);
    cout << "Depth-First Search (DFS Parallel): ";
    start = omp_get_wtime();
    #pragma omp parallel
    {
        #pragma omp single
        {
            g.parlDFS(startVertex, visited);
        }
    }
    end = omp_get_wtime();
    cout << "\nTime: " << end - start << " seconds\n\n";
    cout << "\n";

    fill(visited.begin(), visited.end(), false);
    cout << "Breadth-First Search (BFS): ";
    start = omp_get_wtime();
    g.seqBFS(startVertex,visited);
    end = omp_get_wtime();
    cout << "\nTime: " << end - start << " seconds\n\n";
    cout << "\n";


    fill(visited.begin(), visited.end(), false);
    cout << "Breadth-First Search (BFS): ";
    start = omp_get_wtime();
    g.parlBFS(startVertex,visited);
    end = omp_get_wtime();
    cout << "\nTime: " << end - start << " seconds\n\n";
    

    return 0;
}