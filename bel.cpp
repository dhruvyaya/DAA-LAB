#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int u, v, weight;
};

void bellmanFord(int V, vector<Edge>& edges, int src) {
    vector<long long> dist(V, LLONG_MAX);
    dist[src] = 0;

    // Relax edges V-1 times
    for (int i = 1; i < V; i++) {
        bool updated = false;

        for (Edge e : edges) {
            if (dist[e.u] != LLONG_MAX &&
                dist[e.u] + e.weight < dist[e.v]) {

                dist[e.v] = dist[e.u] + e.weight;
                updated = true;
            }
        }

        if (!updated)
            break;
    }

    // Detect negative-weight cycles
    for (Edge e : edges) {
        if (dist[e.u] != LLONG_MAX &&
            dist[e.u] + e.weight < dist[e.v]) {

            cout << "Negative-weight cycle detected!\n";
            return;
        }
    }

    cout << "\nShortest distances from source " << src << ":\n";

    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << " : ";

        if (dist[i] == LLONG_MAX)
            cout << "Unreachable";
        else
            cout << dist[i];

        cout << endl;
    }
}

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    if (V <= 0 || E < 0) {
        cout << "Invalid graph dimensions!\n";
        return 1;
    }

    vector<Edge> edges(E);

    cout << "Enter edges (source destination weight):\n";

    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;

        if (edges[i].u < 0 || edges[i].u >= V ||
            edges[i].v < 0 || edges[i].v >= V) {
            cout << "Invalid vertex number!\n";
            return 1;
        }
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    if (src < 0 || src >= V) {
        cout << "Invalid source vertex!\n";
        return 1;
    }

    bellmanFord(V, edges, src);

    return 0;
}
