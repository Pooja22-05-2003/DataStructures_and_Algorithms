#include <bits/stdc++.h>
using namespace std;

// Helper function to perform depth-first traversal and calculate distances for each node.
void dfs(int node, vector<vector<int>>& graph, vector<int>& values, vector<int>& distances, vector<bool>& visited) {
    visited[node] = true;
    distances[node] = 0;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, values, distances, visited);
            values[node] += values[neighbor];
            distances[node] += distances[neighbor] + values[neighbor];
        }
    }
}

vector<long> minAndMax(int T_nodes, vector<int>& T_from, vector<int>& T_to) {
    vector<vector<int>> graph(T_nodes + 1); // Create an adjacency list for the tree graph.
    vector<int> values(T_nodes + 1); // Initialize values for each node.
    vector<int> distances(T_nodes + 1); // Initialize distances for each node.
    vector<bool> visited(T_nodes + 1, false); // Initialize visited array for DFS.

    // Build the tree graph.
    for (int i = 0; i < T_from.size(); i++) {
        graph[T_from[i]].push_back(T_to[i]);
        graph[T_to[i]].push_back(T_from[i]);
    }

    // Perform DFS to calculate distances and values for each node.
    dfs(1, graph, values, distances, visited);

    long minSum = 0;
    long maxSum = 0;

    // Calculate the minimum and maximum possible sums of distances.
    for (int i = 1; i <= T_nodes; i++) {
        minSum += distances[i];
        maxSum += distances[i] + values[i];
    }

    return { minSum, maxSum };
}

int main() {
    int T_nodes, T_edges;
    cin >> T_nodes >> T_edges;

    vector<int> T_from(T_edges);
    vector<int> T_to(T_edges);

    for (int i = 0; i < T_edges; i++) {
        cin >> T_from[i] >> T_to[i];
    }

    vector<long> result = minAndMax(T_nodes, T_from, T_to);

    for (long i : result) {
        cout << i << endl;
    }

    return 0;
}
