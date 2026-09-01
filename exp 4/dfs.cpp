#include <iostream>
using namespace std;

void DFS(int graph[][100], int visited[], int vertex, int n)
{
    cout << vertex << " ";
    visited[vertex] = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && visited[i] == 0)
        {
            DFS(graph, visited, i, n);
        }
    }
}

int main()
{
    int n, edges;

    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[100][100] = {0};
    int visited[100] = {0};

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v):" << endl;

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u][v] = 1;
        graph[v][u] = 1;   
    }

    int start;

    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "DFS Traversal: ";
    DFS(graph, visited, start, n);

    return 0;
}