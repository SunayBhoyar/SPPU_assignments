#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <omp.h>
#include <cstdlib>
#include <ctime>

using namespace std;

class Graph
{
public:
    int vertices;
    vector<vector<int>> adj;

    Graph(int v) : vertices(v), adj(v) {}

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected
    }

    void generateLargeGraph(int edges)
    {
        srand(time(0));
        for (int i = 0; i < edges; ++i)
        {
            int u = rand() % vertices;
            int v = rand() % vertices;
            if (u != v)
            {
                addEdge(u, v);
            }
        }
    }

    void sequentialBFS(int start)
    {
        vector<bool> visited(vertices, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (int neighbor : adj[node])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    void sequentialDFSUtil(int v, vector<bool> &visited)
    {
        visited[v] = true;
        for (int neighbor : adj[v])
        {
            if (!visited[neighbor])
            {
                sequentialDFSUtil(neighbor, visited);
            }
        }
    }

    void sequentialDFS(int start)
    {
        vector<bool> visited(vertices, false);
        sequentialDFSUtil(start, visited);
    }

    void parallelBFS(int start)
    {
        vector<bool> visited(vertices, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while (!q.empty())
        {
            int node;
#pragma omp critical
            {
                if (!q.empty())
                {
                    node = q.front();
                    q.pop();
                }
            }

#pragma omp parallel for
            for (int i = 0; i < static_cast<int>(adj[node].size()); ++i)
            {
                int neighbor = adj[node][i];
#pragma omp critical
                {
                    if (!visited[neighbor])
                    {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }
    }

    void parallelDFSUtil(int v, vector<bool> &visited)
    {
        visited[v] = true;

#pragma omp parallel for
        for (int i = 0; i < static_cast<int>(adj[v].size()); ++i)
        {
            int neighbor = adj[v][i];
            bool shouldVisit = false;

#pragma omp critical
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    shouldVisit = true;
                }
            }

            if (shouldVisit)
            {
                parallelDFSUtil(neighbor, visited);
            }
        }
    }

    void parallelDFS(int start)
    {
        vector<bool> visited(vertices, false);
#pragma omp parallel
        {
#pragma omp single
            {
                parallelDFSUtil(start, visited);
            }
        }
    }
};

int main()
{
    int v = 10000;
    int e = 5000;
    Graph g(v);
    g.generateLargeGraph(e);

    double start, end;

    start = omp_get_wtime();
    g.sequentialBFS(0);
    end = omp_get_wtime();
    cout << "Sequential BFS Time: " << end - start << " seconds\n";

    start = omp_get_wtime();
    g.parallelBFS(0);
    end = omp_get_wtime();
    cout << "Parallel BFS Time: " << end - start << " seconds\n";

    start = omp_get_wtime();
    g.sequentialDFS(0);
    end = omp_get_wtime();
    cout << "Sequential DFS Time: " << end - start << " seconds\n";

    start = omp_get_wtime();
    g.parallelDFS(0);
    end = omp_get_wtime();
    cout << "Parallel DFS Time: " << end - start << " seconds\n";

    return 0;
}